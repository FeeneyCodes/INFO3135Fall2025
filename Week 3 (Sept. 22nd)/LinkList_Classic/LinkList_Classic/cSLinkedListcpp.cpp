#include "cSLinkedList.h"

cSLinkedList::cSLinkedList()
{
	sNode* pHead = NULL;	// or "start"
	sNode* pCurrent = NULL;
}

cSLinkedList::~cSLinkedList()
{
}

void cSLinkedList::Insert(std::string newData)
{
	// Is it empty?
	if (this->pHead == NULL)
	{
		// List is empty, so add this here
		sNode* pNewNode = new sNode();
		pNewNode->data = newData;
		//
		this->pHead = pNewNode;
		this->pCurrent = pNewNode;
		// There is no "next" node
		return;
	}

	// There IS something on the list already
	// So add a new node AFTER the "current" node
	sNode* pNewNode = new sNode();
	pNewNode->data = newData;
	// 
	// This new node is pointing to the old 
	//	current nodes next node
	pNewNode->pNext = this->pCurrent->pNext;

	// Make the old current node point this new node
	this->pCurrent->pNext = pNewNode;
	//

	// Move the current to this new node
	this->pCurrent = pNewNode;


	return;
}


bool cSLinkedList::MoveNext(void)
{
	// Set the "current" node to the next node on 
	//	the "current" node...
	
	// Is there another node, tho?
	if (this->pCurrent->pNext == NULL)
	{
		// Oh no, there ISN'T!
		return false;
	}

	// Yup, there is.
	this->pCurrent = this->pCurrent->pNext;
	return true;
}
void cSLinkedList::MoveToHead(void)
{
	this->pCurrent = this->pHead;
	return;
}

bool cSLinkedList::isEmpty(void)
{
	if (this->pHead == NULL)
	{
		return true;
	}
	return false;
}

bool cSLinkedList::FindData(std::string stringToFind)
{
	// Empty? 
	if (this->pHead == NULL)
	{
		return false;
	}

	// Move to start
	this->MoveToHead();

	do
	{
		// Is this it? 
		if (this->pCurrent->data == stringToFind)
		{
			// Yup. 
			return true;
		}

	} while (this->MoveNext());

	return false;
}

// Deletes the CURRENT node
void cSLinkedList::Delete(void)
{
	// Edge case: is there only one node?
	if (this->pHead == this->pCurrent)
	{
		delete this->pHead;
		this->pHead = NULL;
		this->pCurrent = NULL;
		return;
	}

	// Find the node that points to the current node
	sNode* pNodeBeforeCurrent = this->pHead;

	while (pNodeBeforeCurrent->pNext != this->pCurrent)
	{
		pNodeBeforeCurrent = pNodeBeforeCurrent->pNext;
	}
	// Now its 'next' pointer is pointing to the current
	// Set the node BEFORE the current node to 
	//	go to the node AFTER the current node
	pNodeBeforeCurrent->pNext = this->pCurrent->pNext;
	// 
	delete this->pCurrent;
	//
	this->pCurrent = pNodeBeforeCurrent;

	return;
}