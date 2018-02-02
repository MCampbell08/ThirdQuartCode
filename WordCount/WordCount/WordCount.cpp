#include "WordCount.h"
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include "Word.h"

using std::cout;
using std::cin;
using std::endl;

const int maxWordWidth = 20;
std::vector<Word> Words;

void ShowCurrentDirectory()
{	
	DWORD buffSize = GetCurrentDirectoryA(0, nullptr);
	char* currentDirectory = new char[buffSize];
	if (0 == GetCurrentDirectoryA(buffSize, currentDirectory)) // Error
	{
		cout << "Unable to obtain current Directory!?\n";
	}
	else // Not error
	{
		cout << "Current dir = [" << currentDirectory << "]\n";
	}
	delete[] currentDirectory;
}

void WordCount::OpenTextFile(std::string fileName)
{
	ShowCurrentDirectory();
	std::string response = "???";
	std::ifstream textFileStream;
	textFileStream.open(fileName);
	if (!textFileStream.good())
	{
		cout << "Invalid file [" << fileName << "], could not open!" << endl;
	}
	Word word;
	word.setWord(response);
	Words.push_back(word);
	bool existingWord = false;
	int numWords = 0;
	while (textFileStream >> response)
	{
		++numWords;
		for (unsigned int j =  0; j < Words.size(); ++j) {
			if (Words[j].getWord() == response) {
				Words[j].incrementOccurrences();
				existingWord = true;
				break;
			}
		}
		word.setWord(response);
		if (!existingWord)
		{
			Words.push_back(word);
		}
		existingWord = false;
	}
	cout << "Amount of words: " << numWords << endl;
	textFileStream.close();
}

void WordCount::DisplayWordsFound(std::string fileName)
{
	OpenTextFile(fileName);
	
	for (unsigned int j = 1; j < Words.size(); ++j)
	{
		cout << std::left <<"Word " << std::right << std::setw(7) << j  << std::right << ": " << std::left << std::setw(maxWordWidth) << std::left << Words[j].getWord() << std::right << std::setw(7) << Words[j].getOccurrences() <<  " occurrences." << endl;
	}
}

void WordCount::ProcessFile(std::string file)
{
	DisplayWordsFound(file);
}
