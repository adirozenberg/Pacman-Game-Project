#include "Screen.h"




/* this function recives 2 strings and check if the second string is the end of the first string */
bool hasEnding(string fullString, string  ending) {
	if (fullString.length() >= ending.length()) 
		return (0 == fullString.compare(fullString.length() - ending.length(), ending.length(), ending));
	else 
		return false;
}

/* this function fill screenFiles vector with all of ".screen" files in folder */
void readFiles(vector<string>& screenFiles)
{
	string path = ".";
	for (const auto& file : fs::directory_iterator(path))
		if (hasEnding(file.path().string(), "screen"))
			screenFiles.push_back(file.path().string());
		
}
