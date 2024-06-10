#pragma once
#include <string>
#include <vector>
#include <fstream>

class Node
{
protected:
	std::string name;
	long long size;
	std::vector<Node*> children;
public:
	Node(const std::string name, long long size, const std::initializer_list<Node* > &children)
		: name { name }, size { size }, children { children }{}
	Node(Node *node)
		: name{ node->name }, size{ node->size }, children{ node->children }{}

	void recursivePrint(int depth) const;
	void addChildren(Node* node) { children.push_back(node); }
	void recursiveSort(int depth);
	void recursiveSaveToFile(int depth, std::ofstream& outFile) const;
	virtual void recursiveFindOutSize() {}

	long long getSize() const { return size; }
	const std::string &getName() const { return name; }


	~Node();

	friend class Tree;
private:
	std::string divideTheNumber(long long num) const;
};

class CompareNode {
public:
	bool operator() (const Node* first, const Node* second) {
		return first->getSize() > second->getSize();
	}
};
