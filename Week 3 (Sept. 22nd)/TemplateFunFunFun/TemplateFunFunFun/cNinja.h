#pragma once

#include <string>

class cNinja
{
public:
	cNinja();
	int age;
	std::string firstName;
	void Attack(cNinja* pTarget);
	float health;
};
