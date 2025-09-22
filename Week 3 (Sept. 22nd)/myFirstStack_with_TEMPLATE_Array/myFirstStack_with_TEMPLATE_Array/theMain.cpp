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

	cStackArray<int> myIntStack;
	myIntStack.push(3);
	
//	cStackArray* pMyStack = new cStackArray();
	cStackArray<std::string> myStack;

	std::string songName;
	while (songFile >> songName)
	{
//		std::cout << songName << std::endl;
		myStack.push(songName);
	}

	// Print out the data using pop()
	std::cout << "Stack has " << myStack.getStackSize() << std::endl;

	while (myStack.getStackSize() > 0)
	{
		std::string song = myStack.pop();
		//std::cout << song << std::endl;
	}


	return 0;
}

