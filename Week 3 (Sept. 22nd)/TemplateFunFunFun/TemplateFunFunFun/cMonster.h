#pragma once
#include <string>
#include "cNinja.h"

class cMonster
{
public:
	float health;
	std::string firstName;
	void Roar(void);
	int shoeSize;
	void Attack(cNinja* pTheNinja);
};
