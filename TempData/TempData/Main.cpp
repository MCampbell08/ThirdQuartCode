#include "TempData.h"
#include <iostream>

void KeepWindowOpen()
{
	char c;
	std::cin >> c;
}

int main()
{
	std::string filename = "..\\Debug\\Temp1.txt";
	std::string filename2 = "..\\Debug\\Temp2.txt";
	TempData temps;
	temps.ProcessTemperatures(filename);
	temps.ProcessTemperatures(filename2);

	/*
	TempData* pTemps = new TempData();
	pTemps->ProcessTemperatures();
	delete pTemps;
	*/

	KeepWindowOpen();
	return 0;
}