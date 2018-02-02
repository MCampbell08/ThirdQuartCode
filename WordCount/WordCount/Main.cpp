#include "WordCount.h"
#include <iostream>

int main()
{
	std::cout << "This is WordCount!" << std::endl;
	WordCount Demo;
	Demo.ProcessFile("..\\Debug\\Lab04Words.txt");
	return 0;
}