#pragma once

#include <vector>
#include <string>

#include "cPerson.h"

class cNameGenerator
{
public:
	cNameGenerator();

	bool loadNameFiles(std::string lastNameFile, std::string firstNameFile);

	std::string getRandomFirstName(void);
	std::string getRandomLastName(void);
	cPerson getRandomPerson(void);

private:
	std::vector<std::string> vecFirstNames;
	std::vector<std::string> vecLastNames;

	static const std::string LAST_NAME_CACHE_FILE;	//  = "lastname.cache";
	static const std::string FIRST_NAME_CACHE_FILE;	//  = "firstname.cache";

};


