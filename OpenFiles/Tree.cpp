#include "Tree.h"
#include <stdexcept>
#include <iostream>
#include <filesystem>
#include <fstream>
namespace fs = std::filesystem;

void Tree::print() const
{
	if (!_root)
		throw std::runtime_error("Empty filesystem!");

	_root->recursivePrint(0);
}

void Tree::add(Node* node) {
	if (!_root) {
		_root = new Node(node);
		return;
	}
	_root->children.push_back(node);
}

void Tree::sort(){ _root->recursiveSort(0); }

void Tree::makeTreeFromFilesystem(const std::string& folder)
{
	fs::directory_entry dir(folder);
	_root = new DirNode(dir.path().string(), dir.file_size(), {});

	recursiveAddChildrenFromFilesystem(folder, _root);
	_root->recursiveFindOutSize();
}

void Tree::saveToFile(const std::string& nameOfFile) const {
	std::ofstream outFile(nameOfFile);
	if (!outFile)
		throw std::runtime_error("File can not be open");

	_root->recursiveSaveToFile(0, outFile); 
	outFile.close();
}

void Tree::recursiveAddChildrenFromFilesystem(const std::string& folder, Node *currentNode)
{
	fs::path path(folder);
	for (const fs::directory_entry& entry : fs::directory_iterator(path)) {
		try {
			if (entry.is_directory()) {
				Node* node = new DirNode(entry.path().string(), entry.file_size(), {});
				currentNode->addChildren(node);
				recursiveAddChildrenFromFilesystem(entry.path().string(), node);
			}
			else 
				currentNode->addChildren(new FileNode(entry.path().string(), entry.file_size()));
		}
		catch (const std::exception &ex) {
			std::cout << ex.what() << std::endl;
		}
	}
}