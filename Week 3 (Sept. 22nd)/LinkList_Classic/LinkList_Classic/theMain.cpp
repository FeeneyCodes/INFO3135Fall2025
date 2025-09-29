#include <iostream>
#include "cSPriortyQueue.h"
#include <fstream>

int main()
{
	cSPriortyQueue myPQ;
	myPQ.Insert("Mary", 4.0f);
	myPQ.Insert("Michael", 40.0f);
	myPQ.Insert("Robin", 11.0f);

	// Mary
	// Robin
	// Michael
//	std::map<int /*priority*/, std::string> myPQAsAMap;
//
//	myPQAsAMap[4] = "Mary";
//	myPQAsAMap[40] = "Michael";
//	myPQAsAMap[11] = "Robin";


	
	return 0;
}
