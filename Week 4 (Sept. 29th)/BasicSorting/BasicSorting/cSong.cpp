#include "cSong.h"

#include <cstdlib>		// for rand()


//static 
unsigned int cSong::m_NextID = cSong::INITIAL_UNIQUE_ID;


cSong::cSong()
{
	this->rating = 0;
	this->numberOfTimesPlayed = 0;
	// 
	this->m_uniqueID = cSong::m_NextID;
	// Increment the next number by random between 3 and 10
	cSong::m_NextID += (rand() % 7 + 3);
}


unsigned int cSong::getUniqueID(void)
{
	return this->m_uniqueID;
}
