#include <iostream>
#include "cSLinkedList.h"
#include <fstream>

int mainLL()
{
	// SomeSongs_Small.txt
	std::ifstream songFile("SomeSongs_Small.txt");
	// Assume it worked (Yikes!)

	cSLinkedList myLL;

	// Use getline
	const unsigned int MAXLINESIZE = 5000;
	char lineBuffer[MAXLINESIZE] = { 0 };
//	memset(lineBuffer, 0, MAXLINESIZE);
	while (songFile.getline(lineBuffer, MAXLINESIZE))
	{
		std::string sSong(lineBuffer);
//		std::cout << sSong << std::endl;
		myLL.Insert(sSong);
	}

	// Move to the start
	myLL.MoveToHead();

	if (!myLL.isEmpty())
	{
		do
		{
			std::cout << myLL.pCurrent->data << std::endl;

		} while (myLL.MoveNext());		
	}

	std::cout << "------------" << std::endl;
	if (myLL.FindData("Jazz Samba"))
	{
		std::cout << myLL.pCurrent->data << std::endl;
	}

	// 
	myLL.Delete();

	myLL.MoveToHead();

	if (!myLL.isEmpty())
	{
		do
		{
			std::cout << myLL.pCurrent->data << std::endl;

		} while (myLL.MoveNext());
	}


	return 0;
}
