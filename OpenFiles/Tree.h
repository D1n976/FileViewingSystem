#pragma once
#include "Node.h"
#include "DirNode.h"
#include "FileNode.h"

class Tree
{
	Node* _root;
public:
	Tree(Node* root) : _root{ root } {}
	Tree() : _root{ nullptr } {}

	void print() const;
	void add(Node* node);
	void sort();
	void makeTreeFromFilesystem(const std::string& folder);
	void saveToFile(const std::string& nameOfFile) const;

	~Tree() { delete _root; }
private:
	void recursiveAddChildrenFromFilesystem(const std::string& folder, Node* currentNode);
};

