#include <vector>
#include <string>


// Assuming that the 2 vectors are already sorted, 
//	combine the 2 vectors into a larger sorted vector
// NOTE: We aren't returning the sorted vector because it's slow
void merge(
	std::vector<std::string> vecASorted,	// Are sorted already
	std::vector<std::string> vecBSorted,	// Are sorted already
	std::vector<std::string>& vecBigSortedArray)
{
	//std::vector<std::string> vecBigSortedArray;

	unsigned int vecAIndex = 0;
	unsigned int vecBIndex = 0;

	do
	{

		if (vecAIndex >= vecASorted.size())
		{
			// B is the only choice
			vecBigSortedArray.push_back(vecBSorted[vecBIndex]);
			vecBIndex++;
		}
		else if (vecBIndex >= vecBSorted.size())
		{
			// A is the only choice
			vecBigSortedArray.push_back(vecASorted[vecAIndex]);
			vecAIndex++;
		}
		// 
		else if (vecASorted[vecAIndex] < vecBSorted[vecBIndex])
		{
			// A is LT B, so push on A
			vecBigSortedArray.push_back(vecASorted[vecAIndex]);
			vecAIndex++;
		}
		else
		{
			// A is GT (or equal to) B
			// So push back B
			vecBigSortedArray.push_back(vecBSorted[vecBIndex]);
			vecBIndex++;
		}
	} while (
		vecAIndex < vecASorted.size() ||
		vecBIndex < vecBSorted.size());


	//return vecBigSortedArray;
	return;
}

void mergeSort(std::vector<std::string>& vecNames)
{
	// Trivial case
	if (vecNames.size() == 1)
	{
		// it's sorted
		return;
	}
	if (vecNames.size() == 2)
	{
		// Compare the two
		if (vecNames[0] > vecNames[1])
		{
			// Switch them
			std::string temp = vecNames[0];
			vecNames[0] = vecNames[1];
			vecNames[1] = temp;
			// or std::swap
			return;  
		}
	}
	

	// OMG! It's TOOOOO big for little ol' me!!! 
	unsigned int indexCentre = vecNames.size() / 2;

	std::vector<std::string> vecA;
	std::vector<std::string> vecB;
	
	// TODO: Copy 0 to indexCentre values to vecA
	// TODO: Copy indexCenter to end values to vecB

	mergeSort(vecA);
	mergeSort(vecB);
	// These two are sorted, so we call merge() to combine them
	merge(vecA, vecB, vecNames);

	return;
}



	                      




int main()
{
	std::vector<std::string> vecNames
	{ "Michael", "Mary", "Patricia", "Carol", "Betty",
		"Barbara", "Dorothy", "Joan", "Patricia", "Margaret",
		"Helen", "Shirley", "Doris", "Ruth", "Joyce", "Nancy"
		"Virginia", "Jean", "Marilyn", "Elizabeth", "Dolores",
		"Frances", "Lois", "Alice", "Norma", "Evelyn", "Anna" };


	std::vector<std::string> vecA = { "Betty", "Carol", "Patricia" };
	std::vector<std::string> vecB = { "Barbara", "Dorothy", "Joan" };

	std::vector<std::string> vecBigSorted;
	merge(vecA, vecB, vecBigSorted);

	return 0;
}
