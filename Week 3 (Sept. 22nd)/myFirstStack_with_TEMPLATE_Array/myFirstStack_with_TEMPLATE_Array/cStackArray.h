// "Header guard"
#ifndef _cStackArray_HG_
#define _cStackArray_HG_
//#pragma once

//#include <string>

template <class T>
class cStackArray
{
public:
	cStackArray()
	{
		pMyData = new T[sizeOfStack];
	}
	~cStackArray()
	{
		delete[] pMyData;
	}

	// Puts on top of stack
	void push(T newItem)
	{
		// TODO: What if there isn't any room? 
		if (topOfStackIndex == sizeOfStack)
		{
			// TODO: we have to copy the old data
			//		to the new location

			// Save location (pointer) to old array
			T* pOldArray = pMyData;
			unsigned int oldStackSize = sizeOfStack;

			// We will resize the array
			sizeOfStack = sizeOfStack * 2;
			// Allocate this new array
			pMyData = new T[sizeOfStack];

			// Copy old data to new array
			for (unsigned int index = 0; index != oldStackSize; index++)
			{
				pMyData[index] = pOldArray[index];
			}
			// Delete old array
			delete[] pOldArray;
		}
		return;
	}

	// Takes off of top of stack
	T pop(void)
	{
		topOfStackIndex--;

		T theSong = pMyData[topOfStackIndex];

		return theSong;
	}

	//void push_back(T newItem);

	//T getAtIndex(unsigned int index);
	//void setAtIndex(unsigned int index, T newItem);

	unsigned int getStackSize(void)
	{
		return topOfStackIndex;
	}

	//bool isEmpty(void);

	unsigned int topOfStackIndex = 0;
	unsigned int sizeOfStack = 1000;
	T* pMyData;	// = new string[sizeOfStack]

private:
	//void m_resizeArray(void);
};


#endif //_cStackArray_HG_
