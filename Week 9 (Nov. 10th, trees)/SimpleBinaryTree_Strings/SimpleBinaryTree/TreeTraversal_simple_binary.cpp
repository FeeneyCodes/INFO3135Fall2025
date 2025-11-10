#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include <crtdbg.h>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

//class cCity
//{
//	std::string name;
//	unsigned int population;
//	std::string nameOfBestPub;
//};

class Node 
{
public:
	Node* pLeft;
	Node* pRight;
	// Node* pParent;
	std::string theData;
	Node(std::string value) :theData(value), pLeft(NULL), pRight(NULL) {}
	//~Node() {
	// Is this correct? Any potential issues here?
	//	delete pLeft;
	//	delete pRight;
	//}

	void insert(std::string value)
	{
		// Starting at the root, 
		//  choose left or right node based on:
		// Less than -> Left node
		// Greater than -> Right node
		// If the node is NULL, that we insert there

		Node* pCurNode = this;
		this->m_insert(pCurNode, value);


		return;
	}
	// Private: we don't call this
	void m_insert(Node* pCurNode, std::string value)
	{
		// LT or GT the VALUE at this node
		if (value < pCurNode->theData)
		{
			// Left node
			// Anything here? (i.e. == NULL)
			if (pCurNode->pLeft == NULL)
			{
				// Add the node here
				pCurNode->pLeft = new Node(value);
			}
			else
			{
				// Child node ISN'T null (i.e. has data)
				// Recursively call this on the child node
				this->m_insert(pCurNode->pLeft, value);
			}
		}
		if (value > pCurNode->theData)
		{
			// Right node
			// Anything here? (i.e. == NULL)
			if (pCurNode->pRight == NULL)
			{
				// Add the node here
				pCurNode->pRight = new Node(value);
			}
			else
			{
				// Child node ISN'T null (i.e. has data)
				// Recursively call this on the child node
				this->m_insert(pCurNode->pRight, value);
			}
		}
		// The data is the same, what now???

		return;
	}

	void remove(std::string value)
	{
		// TODO: amazing code here
		return;
	}
	// Returns true if found
	bool find(std::string value)
	{
		// TODO: amazing code here
		return false;
	}

	// Some ways to output the node...
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
		std::cout << pNode->theData << " ";
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
	std::ifstream cityFile("CityList.txt");
	if ( ! cityFile.is_open() )
	{
		return -1;
	}

	std::string aCityName;
	std::vector<std::string> vecCities;
	while (cityFile >> aCityName)
	{
		vecCities.push_back(aCityName);
	}
	// Scramble them
	std::random_shuffle(vecCities.begin(), vecCities.end());
	std::ofstream outCityFile("CityListRandom.txt");
	for (std::string city : vecCities)
	{
		outCityFile << city << std::endl;
	}
	outCityFile.close();

	cityFile.close();
	cityFile.open("CityListRandom.txt");
//	cityFile.open("CityList.txt");

	cityFile >> aCityName;

	Node* pRoot = new Node(aCityName);

	// The rest of the cities
	while (cityFile >> aCityName)
	{
		pRoot->insert(aCityName);
	}

	return 0;
}






















































//	~Node() {
//		if (pLeft != NULL) delete pLeft;
//		if (pRight != NULL) delete pRight;
//	}