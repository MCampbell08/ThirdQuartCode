#include "FileSystemUtility.h"
#include <windows.h>
#include <iostream>

using std::cout;

void FileSystemUtility::ShowCurrentDirectory()
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
