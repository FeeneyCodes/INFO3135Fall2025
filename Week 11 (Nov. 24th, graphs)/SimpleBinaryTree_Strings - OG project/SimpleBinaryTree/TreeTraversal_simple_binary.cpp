#define _CRTDBG_MAP_ALLOC
#include <iostream>


class cNode 
{
public:
	cNode* pLeft; 
	cNode* pRight;  

//	cNode* traverseNode_UniforityOfCellSize(unsigned int theValue)
	//{
	//	if (theValue <= 2)
	//	{
	//		return pLeft;
	//	}
	//	else
	//	{
	//		return pRight;
	//	}
	//}
	// The function pointer
	cNode* (*DoBC_Question)(float value,
		                    cNode* pN1, cNode* pN2);
};

// Returns the node based on the question
cNode* (*DoBC_Question)(float value,
	                    cNode* pN1, cNode* pN2);

cNode* UniforityOfCellSize(float value,
	                    cNode* pN1, cNode* pN2)
{
	if (value <= 2)
	{
		return pN1;
	}
	else
	{
		return pN2;
	}
}


int main()
{
	cNode* pRoot = new cNode();

	cNode* pUCS_LE_2 = new cNode();
	cNode* pUCS_GT_2 = new cNode();

	pRoot->pLeft = pUCS_LE_2;
	pRoot->pRight = pUCS_GT_2;

	// Assign the function pointer
	pRoot->DoBC_Question = UniforityOfCellSize;


	pRoot->DoBC_Question(4.0f, pUCS_LE_2, pUCS_GT_2);


	return 0;
}






















































//	~Node() {
//		if (pLeft != NULL) delete pLeft;
//		if (pRight != NULL) delete pRight;
//	}