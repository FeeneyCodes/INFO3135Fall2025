#include <iostream>


int main(int argc, char* argv[])
{

//	int x;
//	x = 10;
	int x = 10;		// two things
	// Your mission, should you choose to accept it:
	// Add 5 to this and output
//
//	x += 5;		//	x = x + 5;
//	std::cout << "x = " << x << std::endl;

	// Get the address of X and store it in a pointer
	int* pX;			// Allocate a spot to hold a pointer
	pX = &x;		// "address of"
	// 1006
	
	// "dereference" the pointer
	*pX += 5;	// Add 5 to "x" in this case

	std::cout << x << std::endl;

		
	return 0;
}
