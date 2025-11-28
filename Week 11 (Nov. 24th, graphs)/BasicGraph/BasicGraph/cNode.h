#pragma once
#include <string>
#include <vector>

class cNode
{
public:
	std::string someData;	// Colour
	std::string name;		// B2, F6, etc.

	std::vector<cNode*> vec_pAdjacentNodes;

	cNode(std::string theName)
	{
		this->name = theName;
	}
};