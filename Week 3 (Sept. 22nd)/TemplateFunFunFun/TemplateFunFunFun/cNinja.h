#pragma once

#include <string>
#include "cMonster.h"

//template <class T>
class cNinja
{
public:
	cNinja();
	int age;
	std::string firstName;
	void Attack(cNinja* pTarget);
	void Attack(cMonster* pTarget);
	//void Attack(T* pTarget)
	//{
	//	std::cout << this->firstName
	//		<< " attacks "
	//		<< pTarget->firstName << std::endl;
	//	pTarget->health -= 10.0f;
	//	return;
	//}

	float health;
};
