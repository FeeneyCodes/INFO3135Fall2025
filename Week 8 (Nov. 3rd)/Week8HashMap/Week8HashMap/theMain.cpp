
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
//Jaxon REALES 96 566_486_097
//Kadynce KUPPINGER 96 020_647_883
//Cristiana MINTER 24 014_603_039
#include "cPerson.h"

#include "cHashMap_A.h"

void LoadPeople(std::vector<cPerson>& vecPeople);

int main()
{
	std::vector<cPerson> vecPeople;
	LoadPeople(vecPeople);


	cHashMap_A hashPeople;

	for (unsigned int index = 0; index != vecPeople.size(); index++)
	{
		cPerson* pCurrentPerson = &( vecPeople[index] );
		hashPeople.addPerson(pCurrentPerson);
	}

	unsigned long loadedCount = hashPeople.getPeopleLoadedCount();



//	// 020_647_883 --> 020647883
//	std::vector<cPerson*> vec_pPeople;
//	// add 1,000,000,000 SIN
//	vec_pPeople.reserve(1'000'000'000);
//	for (unsigned long long count = 0; count != 1'000'000'000; count++)
//	{
//		vec_pPeople.push_back(NULL);
//	}
//	// Kadynce KUPPINGER 96 020_647_883 is the 2nd person in the file
//	vec_pPeople[20647883] = &(vecPeople[1]);

	// Problem is this takes up WAY too much space

	std::map<unsigned long long, cPerson*> mapPeople;
	mapPeople[20647883] = &(vecPeople[1]);

	for (unsigned int index = 0; index != vecPeople.size(); index++)
	{
		mapPeople[vecPeople[index].theSIN] = &(vecPeople[index]);
	}



	// A hash solution
	// Indexed like an array
	// 0 to 
	std::vector<cPerson*> vec_hash_pPeople;
	// add 41,651,653 SIN
//	vec_pPeople.reserve(41'651'653);

	// But we have only 300+ people
	vec_hash_pPeople.reserve(1000);
	for (unsigned long long count = 0; count != 1000; count++)
	{
		vec_hash_pPeople.push_back(NULL);
	}
	//
//	vec_hash_pPeople[20647883] = &(vecPeople[1]);

	// The world's simplest hash function. Huzzah!
	// The vector is 1000 locations...
	unsigned int hashIndex = 20647883 % 1000;
	vec_hash_pPeople[hashIndex] = &(vecPeople[1]);

	for (unsigned int index = 0; index != vecPeople.size(); index++)
	{
//		unsigned int hashIndex = vecPeople[index].theSIN % 1000;

		// Use the last name to hash
		unsigned int hashIndex = 0;
		for (unsigned int charIndex = 0; 
			 charIndex != vecPeople[index].last.size(); charIndex++)
		{
			hashIndex += (int)(vecPeople[index].last[charIndex]);
		}
		hashIndex = hashIndex % 1000;

		vec_hash_pPeople[hashIndex] = &(vecPeople[index]);
	}
	unsigned int count = 0;
	for (unsigned int index = 0; index != vecPeople.size(); index++)
	{
		if (vec_hash_pPeople[index] != NULL)
		{
			count++;
		}
	}

	return 0;
}



void LoadPeople(std::vector<cPerson>& vecPeople)
{
	std::ifstream peopleFile("SomePeople.txt");
	cPerson temp;
	while (peopleFile >> temp.first)
	{
		peopleFile >> temp.last
			>> temp.age
			>> temp.SIN;
		// Convert to an int
		// Kadynce KUPPINGER 96 020_647_883
		std::stringstream ssSIN;
		ssSIN
			<< temp.SIN[0] << temp.SIN[1] << temp.SIN[2]
			<< temp.SIN[4] << temp.SIN[5] << temp.SIN[6]
			<< temp.SIN[8] << temp.SIN[9] << temp.SIN[10];
		ssSIN >> temp.theSIN;

		vecPeople.push_back(temp);
	}
	return;
}