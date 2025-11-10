#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include <crtdbg.h>

class Node 
{
public:
	Node* pLeft;
	Node* pRight;
	int theData;
	Node(int value) :theData(value), pLeft(NULL), pRight(NULL) {}
	//~Node() {
	// Is this correct? Any potential issues here?
	//	delete pLeft;
	//	delete pRight;
	//}
	void inorder(Node* pNode)
	{
		if (pNode == NULL) return;
		inorder(pNode->pLeft);
		std::cout << pNode->pRight << " ";
		inorder(pNode->pRight);
	}

	void preorder(Node* pNode)
	{
		if (pNode == nullptr) return;
		std::cout << pNode->data << " ";
		preorder(pNode->pLeft);
		preorder(pNode->pRight);
	}

	void postorder(Node* pNode)
	{
		if (pNode == nullptr) return;
		postorder(pNode->pLeft);
		postorder(pNode->pRight);
		std::cout << pNode->theData << " ";
	}

	void deallocate(Node* pNode)
	{
		if (pNode == nullptr) return;
		deallocate(pNode->pLeft);
		deallocate(pNode->pRight);
		delete pNode;
	}
};





int main()
{
	// EITHER USE THE #if defined(_DEBUG) at the top of the main OR the
	// _CrtDumpMemoryLeaks(); right before the return statement
	// if in debug mode, you can find the preprocessor definitions at:
	// ProjectProperties-C/C++-Preprocessor-Preprocessor Definitions
	// In debug mode the preprocessor is set to _DEBUG
	// Use this method so it checks for leaks in debug mode
#if defined(_DEBUG)
	// gets the state of the debug flags
	int dbgFlags = ::_CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
	// bitwise or - check block integrity on every memory call
	dbgFlags |= _CRTDBG_CHECK_ALWAYS_DF;
	// don't always remove the blocks on delete
	dbgFlags |= _CRTDBG_DELAY_FREE_MEM_DF;
	// check for memory leaks at process termination
	dbgFlags |= _CRTDBG_LEAK_CHECK_DF;
	// modifies the state of the debug flags
	_CrtSetDbgFlag(dbgFlags);
#endif

	// Build first tree figure from slide 13:
	// 
	//      +-------5-----+
	//      |             |
	//   +--2--+     +---12---+
	//   |     |     |        |
	//   1     3     9    +--21--+
	//                    |      |
	//                   19     25
	//
	Node* pRoot = new Node(5);
	
	pRoot->pLeft = new Node(2);
	pRoot->pRight = new Node(12);
	
	//       (2)
	pRoot->pLeft->pLeft = new Node(1);
	pRoot->pLeft->pRight = new Node(3);
	//       (12)
	pRoot->pRight->pLeft = new Node(9);
	pRoot->pRight->pRight = new Node(21);

	//       (12)    (21)
	pRoot->pRight->pRight->pLeft = new Node(19);
	pRoot->pRight->pRight->pRight = new Node(25);

	// traverse the tree inorder
	std::cout << "Inorder: ";
//	inorder(pRoot);
	std::cout << "\nPreorder: ";
//	preorder(pRoot);
	std::cout << "\nPostorder: ";
//	postorder(pRoot);
	// solution 1:   
	//    Create a destructor that deletes left and right and call delete root;
	// solution 2: 
	//    Traverse the tree and delete nodes
//	deallocate(pRoot);

	// Brute force
	//delete root->right->right->left;
	//delete root->right->right;
	//delete root->left->right->right;
	// etc.

	return 0;
}






















































//	~Node() {
//		if (pLeft != NULL) delete pLeft;
//		if (pRight != NULL) delete pRight;
//	}