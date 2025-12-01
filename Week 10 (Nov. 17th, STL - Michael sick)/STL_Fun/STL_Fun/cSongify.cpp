#include "cSongify.h"
#include <algorithm>

cSongify::cSongify()
{
}

cSongify::~cSongify()
{

}


cPerson g_referencePerson;

// Don't HAVE to pass by reference, but that's pretty conventional...
bool g_DoesSINandSongifyIDMatch(cPerson& A)
{
//if ((itPerson->SIN == newPerson.SIN) &&
//	(itPerson->getSongifyUniqueUserID() == newPerson.getSongifyUniqueUserID()))
	if ((A.SIN == ::g_referencePerson.SIN) &&
		(A.getSongifyUniqueUserID() == ::g_referencePerson.getSongifyUniqueUserID()))
	{
		// They match!
		return true;
	}
	// They DON'T match
	return false;
}

// Same as above but as a functor
class cMatchBySINandSongifyID
{
	cPerson m_referencePerson;
public:
	cMatchBySINandSongifyID(cPerson& referencePerson)
	{
		this->m_referencePerson = referencePerson;
	}
	// Method must use the "()" operator
	bool operator() (cPerson& A)
	{
		if ((A.SIN == this->m_referencePerson.SIN) &&
			(A.getSongifyUniqueUserID() == this->m_referencePerson.getSongifyUniqueUserID()))
		{
			// They match!
			return true;
		}
	}
};


// All these return true if they work, false if not (for any reason)
// You can add some error information to the by reference error string, if you want. 
bool cSongify::AddUser(cPerson newPerson, std::string& errorString)
{
	// Check to see if there is already someone with this SIN and SongifyID

	cPerson p;

//	// We could do a linear search
//	for (std::vector<cPerson>::iterator itPerson = this->m_vecPeople.begin();
//		itPerson != this->m_vecPeople.end(); itPerson++)
//	{
//		// Does this person match?
//		if ( (itPerson->SIN == newPerson.SIN) &&
//			 (itPerson->getSongifyUniqueUserID() == newPerson.getSongifyUniqueUserID()) )
//		{
//			// Oops, they are already in there
//			errorString = "Error: User already in Songify";
//			return false;
//		}
//	}


//	//	We could do a linear search
//	::g_referencePerson = newPerson;
//
//	for (std::vector<cPerson>::iterator itPerson = this->m_vecPeople.begin();
//		itPerson != this->m_vecPeople.end(); itPerson++)
//	{
//		// Does this person match?
//		if ( ::g_DoesSINandSongifyIDMatch( *itPerson ) )
//		{
//			// Oops, they are already in there
//			errorString = "Error: User already in Songify";
//			return false;
//		}
//	}

//	::g_referencePerson = newPerson;		// <-- state data needs to be global?
//	std::vector<cPerson>::iterator itFound = 
//		std::find_if(this->m_vecPeople.begin(), this->m_vecPeople.end(), 
//		             ::g_DoesSINandSongifyIDMatch);

	std::vector<cPerson>::iterator itFound = 
		std::find_if(this->m_vecPeople.begin(), this->m_vecPeople.end(), 
			         cMatchBySINandSongifyID(newPerson) );

//	cMatchBySINandSongifyID findFunctor(newPerson);
//	std::vector<cPerson>::iterator itFound = 
//		std::find_if(this->m_vecPeople.begin(), this->m_vecPeople.end(), 
//			         findFunctor);

	// Return:
	// - points iterator at the matching person 
	//   OR
	// - points iterator at .end()
	if (itFound != this->m_vecPeople.end())
	{
		// Found a match, so can't add
		errorString = "Error: User already in Songify";
		return false;
	}

	// Or use a "functor" which is a class with a predicate function




	// They aren't in Songify
	this->m_vecPeople.push_back(newPerson);
		 

	return true;
}
