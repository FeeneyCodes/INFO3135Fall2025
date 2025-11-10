#pragma once


#pragma once

#include "cPerson.h"
#include <vector>

// DOES handle collisions by using a 
// having a FIXED "bucket" of items at each location
class cHashMap_C
{
public:
	cHashMap_C();
	void addPerson(cPerson* pThePerson);

	// Returns NULL if NOT found
	cPerson* findPerson(
		std::string first,
		std::string last,
		unsigned long long theSIN);

	unsigned long getPeopleLoadedCount(void);

private:
	// Uses the size of the array (val % size)
	unsigned long calcHash_1(unsigned long value);
	// Adds up the characters % array_size
	unsigned long calcHash_2(std::string value);
	// Adds up the XOR % array_size
	unsigned long calcHash_3(std::string value);

	// std::vector<cPerson*> m_vec_hash_People;

	// This has a "list" at each location
	// Now, there's a vector at EACH hash location
	//std::vector< std::vector<cPerson*> > ;

	// This syntax looks a little "sus"
	// 
	// Idea: There's a 100 element array here
	//
	std::vector<cPerson* [100]> m_vec_hash_People;

	unsigned long m_arraySize = 1000;
};
