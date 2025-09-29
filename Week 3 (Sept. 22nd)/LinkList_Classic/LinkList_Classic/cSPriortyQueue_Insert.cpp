#include "cSPriortyQueue.h"


// Will insert after the "current" location
void cSPriortyQueue::Insert(std::string newData, float Priority)
{
	sPQNode* pNew = new sPQNode();
	pNew->data = newData;
	pNew->Priority = Priority;

	// We don't stick it at the "current" node.
	// Instead we scan through the list until we find a node
	//	of higher priority (assiming it's a "low to high" order)

	sPQNode* pTestNode = this->pHead;
	while (pTestNode->Priority < pNew->Priority || 
		   pTestNode == NULL /*end of the list*/)
	{
		// Move to the next node
		pTestNode = pTestNode->pNext;
	}
	// Here either the pTestNode is pointing to the 
	//	node AFTER this priorty 
	//	-- so insert it BEFORE this node
	// OR
	// We're at the end of the list

	// Connect this new node to the prior and next
	pNew->pNext = pTestNode;
	pNew->pPrior = pTestNode->pNext;

	// Point the prior node to this new node
	pTestNode->pPrior->pNext = pNew;
	// Point the pTestNode to this new node
	// (the node that is greater than the one we are adding)
	pTestNode->pPrior = pNew;
}
