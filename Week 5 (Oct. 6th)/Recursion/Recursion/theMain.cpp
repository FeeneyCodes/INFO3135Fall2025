#include <iostream>
#include <vector>
#include <string>

// returns -ve if didn't find it
int findName(std::string name, std::vector<std::string>& vecNames)
{
	for (unsigned int index = 0; index != vecNames.size(); index++)
	{
		if (vecNames[index] == name)
		{
			return index;
		}
	}
	return -1;
}

int findNamesRec(
	std::string nameToFind, unsigned int startIndex,	
	std::vector<std::string>& vecNames)  
{
	// Index to far into vector? 
	if (startIndex == vecNames.size())
	{
		// We are off the end of the vector
		return -1;
	}
	if (vecNames[startIndex] == nameToFind)
	{
		return startIndex;
	}
	return findNamesRec(nameToFind, startIndex + 1, vecNames);
}

int main()
{
	std::vector<std::string> vecNames;
	vecNames.push_back("Michael");
	vecNames.push_back("Mary");
	vecNames.push_back("Patricia");
	vecNames.push_back("Carol");

	int y = findNamesRec("Patricia", 0, vecNames);

//	int x = findName("Patricia", vecNames);


	return 0;
}