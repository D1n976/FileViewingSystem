#pragma once
#include <string>
#include "Node.h"

class FileNode
	: public Node
{
public:
	FileNode(const std::string name, long long size)
		: Node(name, size, {}) {}
};
