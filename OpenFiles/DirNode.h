#pragma once
#include "Node.h"
#include <vector>
#include <initializer_list>

class DirNode
	: public Node
{
public:
	DirNode(const std::string name, long long size, const std::initializer_list<Node* >& children)
		: Node (name, size, children){}
	void recursiveFindOutSize() override;
};