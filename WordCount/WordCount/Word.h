#pragma once
#include <string>
class Word
{
private:
	std::string word;
	int occurrences = 1;

public:
	std::string getWord();
	void setWord(std::string w);
	int getOccurrences();
	void incrementOccurrences();
};

