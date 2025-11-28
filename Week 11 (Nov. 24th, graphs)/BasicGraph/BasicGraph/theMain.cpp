#include "cNode.h"

int main()
{
//B2(start) { B3 }
//B3{ B2, B4 }
//B4{ B3, B5 }
//B5{ B4, B6, C5 }
//
	cNode* pB2 = new cNode("B2");
	cNode* pB3 = new cNode("B3");
	cNode* pB4 = new cNode("B4");
	cNode* pB5 = new cNode("B5");
	cNode* pB6 = new cNode("B6");

	cNode* pC5 = new cNode("C5");


	pB2->someData = "Start node (is green)";
	pB2->vec_pAdjacentNodes.push_back(pB3);

	pB3->vec_pAdjacentNodes.push_back(pB2);
	pB3->vec_pAdjacentNodes.push_back(pB4);

	//B4{ B3, B5 }
	pB4->vec_pAdjacentNodes.push_back(pB3);
	pB4->vec_pAdjacentNodes.push_back(pB5);

	//B5{ B4, B6, C5 }
	pB5->vec_pAdjacentNodes.push_back(pB4);
	pB5->vec_pAdjacentNodes.push_back(pB6);
	pB5->vec_pAdjacentNodes.push_back(pC5);




	return 0;
}
