#include "cNameGenerator.h"
#include <fstream>
#include <iostream>

cNameGenerator::cNameGenerator()
{

}

//static 
const std::string cNameGenerator::LAST_NAME_CACHE_FILE = "lastname.cache";

//static
const std::string cNameGenerator::FIRST_NAME_CACHE_FILE = "firstname.cache";


bool cNameGenerator::loadNameFiles(std::string lastNameFile, std::string firstNameFile)
{



	std::ifstream fileLastName(lastNameFile.c_str());
	if ( ! fileLastName.is_open() )
	{
		// Didn't open the file
		return false;
	}

	std::ifstream fileFirstName(firstNameFile.c_str());
	if ( ! fileFirstName.is_open() )
	{
		// Didn't open file
		fileLastName.close();
		return false;
	}

	// At this point both files are openned
	
	// Read the last name file
	//	name, rank, count, prop100k, cum_prop100k, pctwhite, pctblack, pctapi, pctaian, pct2prace, pcthispanic
	//	SMITH, 1, 2442977, 828.19, 828.19, 70.9, 23.11, 0.5, 0.89, 2.19, 2.4

	std::string theLine;
	while (std::getline(fileLastName, theLine))
	{
		// Clean this up
		this->vecLastNames.push_back(theLine);
	}
	// Delete the 1st line
	std::vector<std::string>::iterator itFirstLocation = this->vecLastNames.begin();
	this->vecLastNames.erase(itFirstLocation);
//	Or this...
//	this->vecLastNames.erase( this->vecLastNames.begin() );

	// Get rid of the "all other names" row, the last row
	std::vector<std::string>::iterator itLastLine = this->vecLastNames.end();
	// This is NOT pointing the end, instead it's one PAST the end
	itLastLine--;	// Now it points to the end
	this->vecLastNames.erase(itLastLine);


	//	Olivia, F, 18451
	//	Emma, F, 17102
	while (std::getline(fileFirstName, theLine))
	{
		this->vecFirstNames.push_back(theLine);
	}

	// Clean up the vectors by keeping only the text before the 1st comma
//	for (unsigned int index = 0; index != this->vecLastNames.size(); index++)
//	{
//		this->vecLastNames[index];
//	}

	for (std::vector<std::string>::iterator itName = this->vecLastNames.begin();
		 itName != this->vecLastNames.end();
		 itName++)
	{
		std::string thisLine = *itName;

		// string.find() returns std::string::npos, which is a large int
		// Note: This is an odd-ball: every other find() returns an iterator
		std::size_t commaIndex = thisLine.find_first_of(',');
		// Truncate rest of line after location 5
		thisLine = thisLine.substr(0, commaIndex);
		// Replace the entire line with just the name
		*itName = thisLine;
	}


	for (std::vector<std::string>::iterator itName = this->vecFirstNames.begin();
		itName != this->vecFirstNames.end();
		itName++)
	{
//		std::string thisLine = *itName;
//
//		// string.find() returns std::string::npos, which is a large int
//		// Note: This is an odd-ball: every other find() returns an iterator
//		std::size_t commaIndex = thisLine.find_first_of(',');
//		// Truncate rest of line after location 5
//		thisLine = thisLine.substr(0, commaIndex);
//		// Replace the entire line with just the name
//		*itName = thisLine;
//
		// in one line...
		// In a strange and mysterious way...
//		*itName = (*itName).substr(0, (*itName).find_first_of(','));

		// Or a more normal typical way (with indirection operator)
		// -> is supposed to look like the same thing as with a pointer
		*itName = itName->substr(0, itName->find_first_of(','));

	}//for (std::vector<std::string>::iterator...


	return true;
}


std::string cNameGenerator::getRandomFirstName(void)
{
	// I'm going to use the EVIL rand()
	// ...which is "fine" if it's random-ish
	// ...and there's less than around 32,000 entries

	int randNameIndex = rand() % (int)(this->vecFirstNames.size() - 1);
	std::string randName = this->vecFirstNames[randNameIndex];
	return randName;
}

std::string cNameGenerator::getRandomLastName(void)
{
	// I'm going to use the EVIL rand()
	// ...which is "fine" if it's random-ish
	// ...and there's less than around 32,000 entries

	int randNamePivotIndex = rand() % (int)(this->vecLastNames.size() - 1);

	// Pick another rand() for offset from pivot location
	// There's 160,000+ names
	// So offset could be 160,000 DIV 32,000 or around 5
	int randNamePivotOffset = (rand() % 10) - 5;

	int randNameIndex = randNamePivotIndex + randNamePivotOffset;
	// Is it too far?
	if (randNameIndex >= this->vecLastNames.size())
	{
		randNameIndex = randNameIndex - (int)this->vecLastNames.size();
	}

	std::string randName = this->vecFirstNames[randNameIndex];
	return randName;
}

cPerson cNameGenerator::getRandomPerson(void)
{
	cPerson newPerson;
	newPerson.first = this->getRandomFirstName();
	newPerson.middle = this->getRandomFirstName();
	newPerson.last = this->getRandomLastName();

	newPerson.postalCode[0] = (char)((unsigned int)(rand() % 26) + 'A');
	newPerson.postalCode[1] = (char)((unsigned int)(rand() % 10) + '0');
	newPerson.postalCode[2] = (char)((unsigned int)(rand() % 26) + 'A');
	newPerson.postalCode[3] = (char)((unsigned int)(rand() % 10) + '0');
	newPerson.postalCode[4] = (char)((unsigned int)(rand() % 26) + 'A');
	newPerson.postalCode[5] = (char)((unsigned int)(rand() % 10) + '0');

	newPerson.age = (rand() % 90) + 10;

	char cSIN[10] = { 0 };	// Clear to zeros
	cSIN[9] = '\0';
	for (unsigned int digitIndex = 0; digitIndex != 9; digitIndex++)
	{
		cSIN[digitIndex] = (unsigned int)(rand() % 10);
	}
	// Can start with a zero (0) but the 2nd digit +shoudln't+ be a zero
	// (to prevent a number like 0000xxxxx)
	if (cSIN[1] == 0)
	{
		// Pick another number between 1 and 9
		cSIN[1] = (unsigned int)(rand() % 9) + 1;
	}
	// Convert to string that atoi() can parse
	for (unsigned int index = 0; index != 9; index++)
	{
		cSIN[index] += '0';
	}
	// Last digit is a zero, so will be accepted as a string
	newPerson.SIN = atoi(cSIN);


	return newPerson;
}
