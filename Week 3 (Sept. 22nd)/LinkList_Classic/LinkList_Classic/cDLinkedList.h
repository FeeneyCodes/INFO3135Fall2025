#pragma once

#pragma once
#include <string>

struct sDLLNode
{
	std::string data;		// Data
	sDLLNode* pNext = NULL;	// 0 or nullptr
	sDLLNode* pPrior = NULL;	// 0 or nullptr
};

class cDLinkedList
{
public:
	cDLinkedList();
	~cDLinkedList();

	sDLLNode* pHead = NULL;	// or 0 or nullptr
	//sNode* pTail
	sDLLNode* pCurrent = NULL;
	// Maybe return NULL if invalid
	//sNode* getCurrent(void);

	// Will insert after the "current" location
	void Insert(std::string newData);

	// Delete the "current" node
	void Delete(void);

	// 
	bool FindData(std::string stringToFind);

	// Like STL iterators
	bool MoveNext(void);
	bool MovePrior(void);
	void MoveToHead(void);

	bool isEmpty(void);

};
