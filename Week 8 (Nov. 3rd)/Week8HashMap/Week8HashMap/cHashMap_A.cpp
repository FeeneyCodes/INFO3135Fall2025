#include "cHashMap_A.h"

cHashMap_A::cHashMap_A()
{
	this->m_vec_hash_People.reserve(this->m_arraySize);
	for (unsigned int count = 0; count != this->m_arraySize; count++)
	{
		this->m_vec_hash_People.push_back(NULL);
	}
}

void cHashMap_A::addPerson(cPerson* pThePerson)
{
	unsigned long hashVal = this->calcHash_1(pThePerson->theSIN);

	this->m_vec_hash_People[hashVal] = pThePerson;

	return;
}


unsigned long cHashMap_A::calcHash_1(unsigned long value)
{
	// Just modulus of the size of the array 
	// very simple
	unsigned int hashIndex = value % this->m_arraySize;
	return hashIndex;
}

unsigned long cHashMap_A::calcHash_2(std::string value)
{
	// Use the last name to hash
	unsigned int hashIndex = 0;
	for (unsigned int charIndex = 0;
		charIndex != value.size(); charIndex++)
	{
		hashIndex += (int)(value[charIndex]);
	}
	hashIndex = hashIndex % this->m_arraySize;

	return hashIndex;
}


unsigned long cHashMap_A::getPeopleLoadedCount(void)
{
	unsigned int count = 0;
	for (unsigned int index = 0; index != m_vec_hash_People.size(); index++)
	{
		if (m_vec_hash_People[index] != NULL)
		{
			count++;
		}
	}

	return count;
}
