#include <iostream>
#include <string>
#include "cNinja.h"

template <class T>
T addThings(T* pArray, unsigned int size)
{
	T total = 0.0f;
	for (unsigned int index = 0; index < size; index++)
	{
		total += pArray[index];
	}
	return total;
}

//class cNinja
//{
//public:
//	int age;
//	std::string firstName;
//	void Attack(void);
//};

//float addThings(float* pArray, unsigned int size)
//{
//	float total = 0.0f;
//	for (unsigned int index = 0; index < size; index++)
//	{
//		total += pArray[index];
//	}
//	return total;
//}
//
//int addThings(int* pArray, unsigned int size)
//{
//	int total = 0.0f;
//	for (unsigned int index = 0; index < size; index++)
//	{
//		total += pArray[index];
//	}
//	return total;
//}


int main()
{
	//float x;
	//int y;
	//double z;
	//long c = x + y * z;

	float* pSomeNumbers = new float[10];
	pSomeNumbers[0] = 92.0f;
	pSomeNumbers[1] = 199.0f;
	float x = addThings<float>(pSomeNumbers, 2);
	std::cout << x << std::endl;

	int* pOtherNumbers = new int[10];
	pOtherNumbers[0] = 92;
	pOtherNumbers[1] = 199;
	int y = addThings<int>(pOtherNumbers, 2);
	std::cout << y << std::endl;

	//cNinja* pNinjas = new cNinja[10];
	//cNinja u = addThings<cNinja>(pNinjas, 2);
//	std::cout << y << std::endl;

	//cNinja sally;	sally.firstName = "Sally";
	//cNinja Ali;		Ali.firstName = "Ali";
	//sally.Attack(&Ali);

	cNinja* pSally = new cNinja();
	pSally->firstName = "Sally";

	cNinja* pAli = new cNinja();
	pAli->firstName = "Ali";

	pSally->Attack(pAli);

	cMonster* pFred = new cMonster();
	pFred->firstName = "Fred";
	pSally->Attack(pFred);

	return 0;
}
