#pragma once

#pragma once
#include <string>

struct sPQNode
{
	std::string data;		// Data
	sPQNode* pNext = NULL;	// 0 or nullptr
	sPQNode* pNext = NULL;
	// 
	float Priority = 0.0f;
};

// This is based on the DOUBLY linked list

class cSPriortyQueue
{
public:
	cSPriortyQueue();
	~cSPriortyQueue();

	sPQNode* pHead = NULL;	// or 0 or nullptr
	//sNode* pTail
	sPQNode* pCurrent = NULL;
	// Maybe return NULL if invalid
	//sNode* getCurrent(void);

	// Will insert after the "current" location
	void Insert(std::string newData, float Priority);

	// Delete the "current" node
	void Delete(void);

	// 
	bool FindData(std::string stringToFind);

	// Like STL iterators
	bool MoveNext(void);
	void MoveToHead(void);

	bool isEmpty(void);

};
