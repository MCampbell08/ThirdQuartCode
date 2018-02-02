#pragma once
#include <string>
class WordCount
{
public:
	void ProcessFile(std::string);

private:
	void OpenTextFile(std::string fileName);
	void DisplayWordsFound(std::string fileName);
};

