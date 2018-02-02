#include "Word.h"


std::string Word::getWord()
{
	return word;
}

void Word::setWord(std::string w)
{
	word = w;
}

int Word::getOccurrences()
{
	return occurrences;
}

void Word::incrementOccurrences()
{
	++occurrences;
}
