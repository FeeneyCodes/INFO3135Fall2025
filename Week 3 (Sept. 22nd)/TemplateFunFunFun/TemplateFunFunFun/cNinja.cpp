#include "cNinja.h"
#include <iostream>

cNinja::cNinja()
{
	this->age = 0;
	this->firstName = "";
	this->health = 100.0f;
}

//void cNinja::Attack(cNinja* pTarget)
//{
//	std::cout << this->firstName
//		<< " attacks "
//		<< pTarget->firstName << std::endl;
//	pTarget->health -= 10.0f;
//	return;
//}
//
//void cNinja::Attack(cMonster* pTarget)
//{
//	std::cout << this->firstName
//		<< " attacks "
//		<< pTarget->firstName << std::endl;
//	pTarget->health -= 10.0f;
//	return;
//}
