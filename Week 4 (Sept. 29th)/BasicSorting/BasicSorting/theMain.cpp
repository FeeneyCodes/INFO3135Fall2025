#include <iostream>
#include <vector>
#include "cSong.h"
#include <fstream>

void PrintOutVecStrings(std::vector<std::string> vecSongNamess);
void PrintOutVecSongs(std::vector<cSong> vecSongs);

cSong makeRandomSong(std::vector<std::string> vecSongNames);

void BubbleSortSongs(std::vector<std::string> &vecSongNames);

int main()
{

	// SomeSongs_Small.txt
	std::ifstream songFile("SomeSongs_Small.txt");
	// Assume it worked (Yikes!)

	std::vector<std::string> vecSongNames;

	// Use getline
	const unsigned int MAXLINESIZE = 5000;
	char lineBuffer[MAXLINESIZE] = { 0 };
//	memset(lineBuffer, 0, MAXLINESIZE);
	while (songFile.getline(lineBuffer, MAXLINESIZE))
	{
		std::string sSong(lineBuffer);
//		std::cout << sSong << std::endl;
		vecSongNames.push_back(sSong);
	}

	std::cout << vecSongNames.size() << " songs" << std::endl;

	PrintOutVecStrings(vecSongNames);


	std::cout << "---------------------" << std::endl;
	BubbleSortSongs(vecSongNames);

	PrintOutVecStrings(vecSongNames);






	std::vector<cSong> vecSongs;
	for (unsigned int count = 0; count != 10; count++)
	{
		vecSongs.push_back(makeRandomSong(vecSongNames));
	}

//	PrintOutVecSongs(vecSongs);



	return 0;
}

void BubbleSortSongs(std::vector<std::string>& vecSongNames)
{
	bool bIsSorted = false;
	unsigned int numPasses = 0;

	while ( ! bIsSorted )
	{
		// Assume the list IS sorted (like from the last pass)
		bIsSorted = true;
		numPasses++;
		for (unsigned int index = 0; 
			 index != (vecSongNames.size() - 1); 
			 index++)
		{
			// Compare current with next
			if (vecSongNames[index] > vecSongNames[index + 1])
			{
				// Swap them (they are out of order)
				std::string temp = vecSongNames[index + 1];
				vecSongNames[index + 1] = vecSongNames[index];
				vecSongNames[index] = temp;
				bIsSorted = false;
			}
		}
	}//while ( ! bIsSorted )
	// It's sorted! Huzzah!

	return;
}





void PrintOutVecStrings(std::vector<std::string> vecSongs)
{
	for (unsigned int index = 0; index != vecSongs.size(); index++)
	{
		std::cout << vecSongs[index] << std::endl;
	}

	return;
}

void PrintOutVecSongs(std::vector<cSong> vecSongs)
{
	for (unsigned int index = 0; index != vecSongs.size(); index++)
	{
		std::cout 
			<< vecSongs[index].getUniqueID() << " : "
			<< vecSongs[index].name << " by " 
			<< vecSongs[index].artist << std::endl;
	}

	return;
}

const unsigned int NUM_ARTISTS = 7;
std::string artists[NUM_ARTISTS] =
{
	"Michael", "Dua Lipa", "Taylor Swift", "Skrillex", "Daft Punk",
	"Raffi", "Peter Devlin"
};

cSong makeRandomSong(std::vector<std::string> vecSongNames)
{
	cSong NewSong;

	NewSong.artist = artists[rand() % NUM_ARTISTS];
	NewSong.name = vecSongNames[rand() % vecSongNames.size()];

	return NewSong;
}
