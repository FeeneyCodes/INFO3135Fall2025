#pragma once

#include <string>
#include "cMonster.h"

class cNinja
{
public:
	cNinja();
	int age;
	std::string firstName;
	void Attack(cNinja* pTarget);
	void Attack(cMonster* pTarget);
	float health;
};
