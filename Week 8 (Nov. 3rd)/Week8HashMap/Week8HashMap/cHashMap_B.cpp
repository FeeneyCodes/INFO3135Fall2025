#include "cHashMap_B.h"

cHashMap_B::cHashMap_B()
{
	this->m_vec_hash_People.reserve(this->m_arraySize);
	for (unsigned int count = 0; count != this->m_arraySize; count++)
	{
		std::vector<cPerson*> emptyVec;
		this->m_vec_hash_People.push_back(emptyVec);
	}
}

void cHashMap_B::addPerson(cPerson* pThePerson)
{
	unsigned long hashVal = this->calcHash_1(pThePerson->theSIN);

	// Is there already a person at that location
	// 
	// vector< vector<cPerson*> > m_vec_hash_People;

	if (this->m_vec_hash_People[hashVal].size() == 0)
	{
		// Nobody is here, yet
		this->m_vec_hash_People[hashVal].push_back(pThePerson);
	}
	else
	{
		// We SHOULD see if this person is already here...
		// TODO: for future you...
		// For now, this is the same thing
		this->m_vec_hash_People[hashVal].push_back(pThePerson);
	}

	return;
}


// Returns NULL if NOT found
cPerson* cHashMap_B::findPerson(
	std::string first,
	std::string last,
	unsigned long long theSIN)
{
	// Using the same hash function, get the hash value (location)
	unsigned long hashVal = this->calcHash_1(theSIN);

	// Anyone there?
	if (this->m_vec_hash_People[hashVal].size() == 0)
	{
		// Nope. No one there. Didn't find that person
		return NULL;
	}
	// They MIGHT be there
	// Scan through the vector at that location, looking for a 
	//	match. If so, return that person
	// TODO:
	for (cPerson* pPPerson : this->m_vec_hash_People[hashVal])
	{
		// Is this a match
		if ((pPPerson->first == first) &&
			(pPPerson->last == first) &&
			(pPPerson->theSIN == theSIN))
		{
			// Yup.
			return pPPerson;
		}
	}// for (cPerson* pPPerson ...
	// Went through vector and DIDN'T find them
	return NULL;
}



unsigned long cHashMap_B::calcHash_1(unsigned long value)
{
	// Just modulus of the size of the array 
	// very simple
	unsigned int hashIndex = value % this->m_arraySize;
	return hashIndex;
}

unsigned long cHashMap_B::calcHash_2(std::string value)
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

// Adds up the XOR % array_size
unsigned long cHashMap_B::calcHash_3(std::string value)
{
	// Use the last name to hash
	unsigned int hashIndex = 0;
	for (unsigned int charIndex = 0;
		charIndex != value.size(); charIndex++)
	{
		int curChar = (int)(value[charIndex]);
		// XOR some prime number (here it's 17)
		// https://en.wikipedia.org/wiki/Bitwise_operations_in_C
		curChar = curChar ^ 17;
		hashIndex += curChar;
	}
	hashIndex = hashIndex % this->m_arraySize;

	return hashIndex;
}

unsigned long cHashMap_B::getPeopleLoadedCount(void)
{
	unsigned int count = 0;
	for (unsigned int index = 0; index != m_vec_hash_People.size(); index++)
	{
		count += this->m_vec_hash_People[index].size();
	}

	return count;
}
