#pragma once

#include "cPerson.h"
#include <vector>

class cHashMap_A
{
public:
	cHashMap_A();
	void addPerson(cPerson* pThePerson);

	unsigned long getPeopleLoadedCount(void);

private:
	// Uses the size of the array (val % size)
	unsigned long calcHash_1(unsigned long value);
	// Adds up the characters % array_size
	unsigned long calcHash_2(std::string value);

	std::vector<cPerson*> m_vec_hash_People;

	unsigned long m_arraySize = 1000;
};
