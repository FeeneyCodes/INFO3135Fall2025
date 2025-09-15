// "Header guard"
#ifndef _cStackArray_HG_
#define _cStackArray_HG_
//#pragma once

#include <string>

class cStackArray
{
public:
	cStackArray();
	~cStackArray(); 

	void push(std::string newItem);	// Puts on top of stack
	std::string pop(void);		// Takes off of top of stack

	unsigned int getStackSize(void);
	bool isEmpty(void);

	unsigned int topOfStackIndex = 0;
	unsigned int sizeOfStack = 1000;
	//std::string myData[sizeOfStack];
	std::string* pMyData;	// = new string[sizeOfStack]

	// int errorState
	// int getLastError();
};


#endif //_cStackArray_HG_
