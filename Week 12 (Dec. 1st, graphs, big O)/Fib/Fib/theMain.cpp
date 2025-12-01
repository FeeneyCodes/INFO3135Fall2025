#include <iostream>
// 0 1 2 3 4 5 6  7
// 0 1 1 2 3 5 8 13

const unsigned long NUM_FIBS = 100;
unsigned long long g_myFibs[NUM_FIBS] = { 0 };


unsigned int numCalls = 0;
int Fibonacci(int number)
{
    numCalls++;
    if (number <= 1) return number;
    
    // See if I alreay calculated this?
    if ( ::g_myFibs[number] == 0)
    {
        // Nope, I need to calculate this
        ::g_myFibs[number] = Fibonacci(number - 2) + Fibonacci(number - 1);
    }
    // At this point the number is in the array
    return ::g_myFibs[number];
}

int main()
{
    Fibonacci(99);
    numCalls = 0;
    Fibonacci(99);

    for (int fN = 0; fN < NUM_FIBS; fN++)
    {
        numCalls = 0;
        std::cout << "fN(" << fN << ") = "
            << Fibonacci(fN) 
            << " numcalls = " << numCalls 
            << std::endl;
    }

    return 0;
}
