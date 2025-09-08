#include <iostream>

//int Add5(int y)
//{
//	int z = y + 5;
//	return z;
//}

//void Add5(int &y)		// Really the pointer
//{
//	y += 5;
//	return;
//}

// How to pass "by ref" in C
void Add5(int* pY)		// Really the pointer
{
	*pY += 5;
	return;
}

//int addArray(int myArray[], unsigned int sizeOfArray)
//{
//	std::cout << sizeof(myArray) << std::endl;
//
//	int theTotal = 0;
//	for (unsigned int index = 0; index != sizeOfArray; index++)
//	{
//		theTotal += myArray[index];
//	}
//	return theTotal;
//}

//int addArray(int myArray[], unsigned int sizeOfArray)
int addArray(int* myArray, unsigned int sizeOfArray)
{
	int theTotal = 0;
	for (unsigned int index = 0; index != 4; index++)
	{
		theTotal += myArray[index];
	}
	return theTotal;
}

struct sThingToReturn
{
	int total;
	int average;

// For fun, please try:
// - redo what Feeney just did
// - Do a differnt thing with your list
// - Return: Total AND Average AND min AND max

int main(int argc, char* argv[])	// char* argv[]
{
	const unsigned int sizeOfarray = 4;
	int myArray[sizeOfarray] = { 773, 7, -2, 8 };
//	int myArray[sizeOfarray] = { 0 };

	std::cout << sizeof(int) << std::endl;
	std::cout << sizeof(myArray) << std::endl;

	int numOfElements = sizeof(myArray) / sizeof(int);

	std::cout << addArray(myArray, sizeOfarray) << std::endl;


//	int x;
//	x = 10;
	int x = 10;		// two things
	int y = 25;
//	int* pX = &x;
	Add5(&x);
//	std::cout << x << std::endl;


	
	
	//	Add5(x);




	// Your mission, should you choose to accept it:
	// Add 5 to this and output
//
//	x += 5;		//	x = x + 5;
//	std::cout << "x = " << x << std::endl;
//	int a = Add5(x);


//	int* pX;			// Allocate a spot to hold a pointer
//	pX = &x;		// "address of"
	// "dereference" the pointer
//	*pX += 5;	// Add 5 to "x" in this case
//	std::cout << x << std::endl;

		
	return 0;
}



// //	int x;
// //	x = 10;
// int x = 10;		// two things
// // Your mission, should you choose to accept it:
// // Add 5 to this and output
// //
// //	x += 5;		//	x = x + 5;
// //	std::cout << "x = " << x << std::endl;
// 
// 	// Get the address of X and store it in a pointer
// int* pX;			// Allocate a spot to hold a pointer
// pX = &x;		// "address of"
// // 1006
// 
// // "dereference" the pointer
// *pX += 5;	// Add 5 to "x" in this case
// 
// std::cout << x << std::endl;
