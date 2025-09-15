#include "cStackArray.h"
#include <fstream>
#include <iostream>

int main(int argc, char* argv[])
{
	std::ifstream songFile("SomeSongs.txt");
	if (!songFile.is_open())
	{
		std::cout << "Can't find file" << std::endl;
		return -1;
	}

//	cStackArray myStack;
//	myStack.pop();
	
	cStackArray* pMyStack = new cStackArray();

	std::string songName;
	while (songFile >> songName)
	{
//		std::cout << songName << std::endl;
		pMyStack->push();
	}

	// Print out the data using pop()

	delete pMyStack;

	return 0;
}
