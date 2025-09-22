#pragma once
#include <string>

struct sNode
{
	std::string data;		// Data
	sNode* pNext = NULL;	// 0 or nullptr
};

class cSLinkedList
{
public:
	cSLinkedList();
	~cSLinkedList();

	sNode* pHead = NULL;	// or 0 or nullptr
	//sNode* pTail
	sNode* pCurrent = NULL;	
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
	void MoveToHead(void);

	bool isEmpty(void);

};
