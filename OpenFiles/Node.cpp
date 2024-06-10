#include "Node.h"
#include <iostream>
#include <filesystem>
#include <algorithm>
#include <typeinfo>
#include <sstream>
namespace fs = std::filesystem;

void Node::recursivePrint(int depth) const
{
	for (int i = 0; i < depth; i++)
		std::cout << " ";
	std::cout << name << " = " << divideTheNumber(size) << " bytes" <<  std::endl;

	for (Node* child : children)
		child->recursivePrint(depth + 1);
}

void Node::recursiveSort(int depth)
{
	std::sort(children.begin(), children.end(), CompareNode());

	for (Node* child : children)
		child->recursiveSort(depth + 1);
}

void Node::recursiveSaveToFile(int depth, std::ofstream &outFile) const
{
	outFile << name << " = " << divideTheNumber(size) << " bytes" << std::endl;

	for (Node* child : children)
		child->recursiveSaveToFile(depth + 1, outFile);
}

Node::~Node()
{
	for (Node* child : children)
		delete child;
}

std::string Node::divideTheNumber(long long num) const
{
	std::stringstream stream;	//Преобразовать число к строке
	stream << num;
	std::string result(stream.str());

	int countOfNum = 0;
	for (int i = result.size(); i > 0; i--, countOfNum++) {		//Вставить пробел
		if (countOfNum == 3) {
			result.insert(i, " ");
			countOfNum = 0;
		}
	}
	return result;
}
