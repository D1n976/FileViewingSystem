#include "DirNode.h"
#include <typeinfo>
#include <filesystem>
namespace fs = std::filesystem;

void DirNode::recursiveFindOutSize()
{
	for (Node* child : children)
		if (fs::directory_entry(child->getName()).is_directory())
			child->recursiveFindOutSize();

	long long dirSize = 0;
	for (const Node* child : children)
		dirSize += child->getSize();
	size = dirSize;
}
