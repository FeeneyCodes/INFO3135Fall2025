#include "cMusicGenerator.h"
#include "cPersonGenerator.h"
#include "cSong.h"
#include "cPerson.h"

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

#include "helperFunctions.h"


void MakeSomePeople(void)
{
	std::ofstream peopleFile("SomePeople.txt");

	cPersonGenerator* pPG = new cPersonGenerator();


	std::string errorString;
	std::string babyNameFile = "Data/Popular Baby Names/names/yob2019.txt";
	std::string surnameFile = "Data/Surnames/names/Names_2010Census.csv";
	std::string streetNameFile = "Data/Street Names (San Francisco)/Street_Names.csv";

	std::cout << "Loading the census data...";
	if (!pPG->LoadCensusFiles(babyNameFile, surnameFile, streetNameFile, errorString))
	{
		std::cout << "\nDidn't load census files because: " << errorString << std::endl;
		delete pPG;
		return;
	}
	std::cout << "done." << std::endl;

	const unsigned int NUM_PEOPLE_TO_MAKE = 500;

	for (unsigned int count = 0; count != NUM_PEOPLE_TO_MAKE; count++)
	{
		cPerson temp = pPG->generateRandomPerson();
		peopleFile
			<< temp.first << " "
			<< temp.last << " "
			<< temp.age << " ";
	//		<< printablePhoneNumber(temp.phoneNumbers[0]) << " ";
		std::string theSIN = printableSIN(temp.SIN);
		theSIN[3] = '_';
		theSIN[7] = '_';
		peopleFile << theSIN
			<< std::endl;
	}

	std::cout << "Made " << NUM_PEOPLE_TO_MAKE << std::endl;

	peopleFile.close();

	return;
}
