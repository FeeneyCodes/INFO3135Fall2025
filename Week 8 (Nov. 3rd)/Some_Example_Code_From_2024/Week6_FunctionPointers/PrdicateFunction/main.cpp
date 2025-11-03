
#include <iostream>

int add(const int a, const int b)
{
	return a + b;
}

int sub(const int a, const int b)
{
	return a - b;
}

// More "modern" C++
//using function_signature = int(*)(const int, const int);

// WAY more likely to see this:
int(*function_to_call)(const int, const int);


int main(int argc, char* argv[])
{
	int a,b;
	std::cout << "Enter an integer: ";
	std::cin >> a;

	std::cout << "Enter an integer: ";
	std::cin >> b;

//	function_signature function_to_call = nullptr;
	function_to_call = nullptr;

	std::cout << "Enter '1' to add or '2' to subtract: ";
	int operation;
	std::cin >> operation;

	if(operation == 1)
	{
		std::cout << "Adding " << a << " + " << b << " ";
		function_to_call = add;
	}else
	{
		std::cout << "Subtracting " << a << " + " << b << " ";
		function_to_call = sub;
	}

	// int(*function_to_call)(const int, const int);
	const int result = function_to_call(a,b);

	std::cout << "== " << result << std::endl;	
}
