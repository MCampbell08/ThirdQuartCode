#include "WordPlay.h"
#include <iostream>
#include <string>
#include <iomanip>
#include "FileSystemUtility.h"

using std::cout;
using std::cin;
using std::endl;

const int maxWordWidth = 20;

void RunThis();

void WordPlay::Run()
{
	RunThis();
}

void WordPlay::ProcessInput1() // read one word
{
	cout << "1: Please enter one or more words followed by enter: ";
	std::string response = "???";
	cin >> response;
	cout << "Here is your response [" << response << "]\n";
}

void WordPlay::ProcessInput2() // read one line
{
	cout << "2: Please enter one or more words followed by enter: ";
	const int bufferSize = 1024;
	char response[bufferSize];
	cin.getline (response, bufferSize);
	cout << "Here is your response [" << response << "]\n";
}

void WordPlay::ProcessInput3() // read all words on line
{
	cout << "3: Please enter one or more words followed by enter: ";
	std::string response = "???";
	while (cin >> response)
	{
		cout << "Here is one word of your repsonse [" << response << "]\n";
	}
}

void WordPlay::ProcessInput4() // analyze each word on a line
{
	cout << "4: Please enter one or more words followed by enter: ";
	std::string response = "???";
	int numWords = 0;
	while (cin >> response)
	{
		//if (response == "stop") break;
		++numWords;
		int numChars = response.length();
		response = "[" + response + "]";
		cout << std::setw(2) << std::right << numWords << ": " << std::setw(maxWordWidth) << std::left << response << " has " << std::left << numChars << " chars.\n";
	}
}

#include <fstream> // Bad practice placing in middle
//#include <Windows.h>

//void ShowCurrentDirectory()
//{	
//	DWORD buffSize = GetCurrentDirectoryA(0, nullptr);
//	char* currentDirectory = new char[buffSize];
//	if (0 == GetCurrentDirectoryA(buffSize, currentDirectory)) // Error
//	{
//		cout << "Unable to obtain current Directory!?\n";
//	}
//	else // Not error
//	{
//		cout << "Current dir = [" << currentDirectory << "]\n";
//	}
//	delete[] currentDirectory;
//}

void WordPlay::ProcessInput5()
{
	FileSystemUtility::ShowCurrentDirectory();
	std::string response = "???";
	std::ifstream textFileStream;
	std::string filename = "..\\Debug\\Text5.txt";
	textFileStream.open(filename);
	if (!textFileStream.good())
	{
		cout << "Unable to open file [" << filename << "], quitting!\n";
		return;
	}
	int numWords = 0;
	while (textFileStream >> response)
	{
		//if (response == "stop") break;
		++numWords;
		int numChars = response.length();
		response = "[" + response + "]";
		cout << std::setw(2) << std::right << numWords << ": " << std::setw(maxWordWidth) << std::left << response << " has " << std::left << numChars << " chars.\n";
	}
	textFileStream.close();
}

void WordPlay::ProcessInput6 ()
{
	cout << "6: Please enter a name followed by an age followed by enter: ";
	std::string name = "??";
	int age = -1;
	age = 0;
	cin >> name >> age;
	cout << "Name = [" << name << "], age = [" << age << "]." << endl;
	
	//Some definitions
	//
	// A types defines a set of possible values and a set of operations.
	// An object is some memory that holds a value of a given type.
	// A value is a set of bits in memory interpreted according to its type.
	// A variable is a named object.
	// A declaration is a statement that gives a name to an object.
	// A definition is a declaration that sets aside memory for an object.
	//
	//
	//
	//
}

int Method1 (int j) 
{
	j = j + 1;
	return j;
}

int Method2(int* j)
{
	*j = *j + 1;
	return *j;
}

void RunThis()
{
	int j = 7; 
	int k = Method1(j);
	cout << "j, k = " << j << ", " << k << endl;

	int j2 = 7;
	int k2 = Method2(&j2);
	cout << "j2, k2 = " << j2 << ", " << k2 << endl;

	int j3[] = {0, 1, 2, 3, 4, 5, 6, 7};
	int num = sizeof(j3) / sizeof(j3[0]);
	for (int m = 0; m < num; ++m)
	{
		cout << "j3[" << m << "] = " << j3[m] << endl;
	}
	int *p = &j3[0];
	cout << "=====\n";
	for (int m = 0; m < num; ++m)
	{
		int value = *p;
		++p;
		//p = p + 1
		cout << "j3[" << m << "] = " << value << endl;
	}
}