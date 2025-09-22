//#include "cStackArray.h"
//
//
//cStackArray::cStackArray()
//{
//	// Allocate the array
//	// unsigned int sizeOfStack = 1000;
//	// string* pMyData = new string[sizeOfStack]
//	pMyData = new std::string[sizeOfStack];
//
//}
//
//cStackArray::~cStackArray()
//{
//	// Get rid of everything 
//	delete [] pMyData;
//}
//
//// Puts on top of stack
//void cStackArray::push(std::string newItem)
//{
//	// TODO: What if there isn't any room? 
//	if (topOfStackIndex == sizeOfStack)
//	{
//		// TODO: we have to copy the old data
//		//		to the new location
//
//		// Save location (pointer) to old array
//		std::string* pOldArray = pMyData;
//		unsigned int oldStackSize = sizeOfStack;
//
//		// We will resize the array
//		sizeOfStack = sizeOfStack * 2;
//		// Allocate this new array
//		pMyData = new std::string[sizeOfStack];
//
//		// Copy old data to new array
//		for (unsigned int index = 0; index != oldStackSize; index++)
//		{
//			pMyData[index] = pOldArray[index];
//		}
//		// Delete old array
//		delete[] pOldArray;
//
//	}
//
//
//	// Move to the top of stack
//	pMyData[topOfStackIndex] = newItem;
//	// Next item goes here:
//	topOfStackIndex++;
//
//	return;
//}
//
//unsigned int cStackArray::getStackSize(void)
//{
//	return topOfStackIndex;
//}
//
//
//// Takes off of top of stack
//std::string cStackArray::pop(void)
//{
//	// TODO: What if the stack is empty??
//
//	// The top is one more than the 
//	//	acutal location of the data
//	topOfStackIndex--;
//
//	std::string theSong = pMyData[topOfStackIndex];
//
//	return theSong;
//}
