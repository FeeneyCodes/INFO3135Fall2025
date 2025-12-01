#include <iostream>


#include "cNameGenerator.h"
#include "Songify_helperFunctions.h"



int main()
{
	cNameGenerator* pNG = new cNameGenerator();

	if (!pNG->loadNameFiles("data/Names_2010Census.csv", "data/yob2019.txt"))
	{
		std::cout << "Error: Didn't load one or more name files." << std::endl;
		return -1;
	}

	cPerson p = pNG->getRandomPerson();

	std::cout << printablePerson(p, true) << std::endl;


	return 0;
}
