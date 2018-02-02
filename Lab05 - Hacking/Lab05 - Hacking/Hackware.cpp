#include "Hackware.h"
#include <iostream>
#include <vector>
#include <random>
#include <string>

using std::cout;	
using std::endl;
using std::cin;

int correctPlace = 0;
int incorrectPlace = 0;
int correctNumber = 0;
int numGuess = 0;

Hackware::Hackware()
{
}

Hackware::~Hackware()
{
}

std::vector<int> Hackware::CreatePassword(int passwordLength)
{
	int randomizedNum = 0;
	if (passwordLength < 3 && passwordLength > 8) {
		cout << "Error: Password length of [" << passwordLength << "], is incorrect!\nAutomatically setting Password length to 4" << endl;
		passwordLength = 4;
	}
	
	for (int j = 0; j < passwordLength; ++j) {
		std::random_device randEngine;
		std::uniform_int_distribution<int> randDist(0, 9);
		randomizedNum = randDist(randEngine);
		PasswordCharacters.push_back(randomizedNum);
	}
	return PasswordCharacters;
}

bool Hackware::InputAsString()
{
	std::string userInput;
	UserGuess.clear();
	cin >> userInput;
	for (size_t k = 0; k < userInput.size(); ++k)
	{
		char c = userInput[k];
		int isDigit = isdigit(c);
		if (isDigit)
		{
			int value = c - '0';
			UserGuess.push_back(value);
		}
	}
	return true;
}

bool Hackware::HackTerminal(std::vector<int> password, int numberOfTries)
{
	if (numberOfTries < 3 && numberOfTries > 8) {
		cout << "Error: Amount of attempts: [" << numberOfTries << "], is incorrect!\nAutomatically setting amount of attempts to 4" << endl;
		numberOfTries = 4;
	}
	cout << "The password length is [" << password.size() << "]. You have [" << numberOfTries << "] tries to guess correctly."  << endl;

	while (!hackingFinished)
	{
		if (!InputAsString())
		{
			cout << "Input failed" << endl;
		}
		numGuess++;
		for (size_t j = 0; j < password.size(); ++j)
		{
			for (size_t k = 0; k < password.size(); ++k) 
			{
				if (UserGuess[k] == password[j])
				{
					correctNumber++;
					if (k == j)
					{
						correctPlace++;
					}
					else
					{
						incorrectPlace++;
					}
				}
			}
		}
		DisplayCases();
		SetDupliGuess();
		correctNumber  = 0;
		incorrectPlace = 0;
		correctNumber  = 0;
	}
	return true;
}
bool Hackware::DisplayCases()
{
	if (numGuess == 4)
	{
		cout << "You failed and security was alerted! 12 Synth troopers and a Legendary Synth leader are inbound..." << endl;
		hackingFinished = true;
	}
	else
	{
		if      (correctNumber == 0) {
			cout << "Guess " << numGuess << ": " << UserGuess[0] << UserGuess[1] << UserGuess[2] << UserGuess[3] << " - " << correctNumber << " digits were correct and " << incorrectPlace << " digits were incorrectly placed." << endl;
		}
		else if (UserGuess == PasswordCharacters)
		{
			cout << "Sweet! You're in!" << endl;
			hackingFinished = true;
		}
		else if (UserGuess == PrevUserGuess)
		{
			cout << "Oh, you wasted a guess! You answered with the same guess as before!" << endl;
			PrevUserGuess.clear();
		}
		else if (CheckDupliDigits()) 
		{
			cout << "Oh, you wasted a guess! All digits must be different!" << endl;
		}
		else
		{
			cout << "Guess " << numGuess << ": " << UserGuess[0] << UserGuess[1] << UserGuess[2] << UserGuess[3] << " - " << correctNumber << " digits were correct and " << incorrectPlace << " digits were incorrectly placed." << endl;
		}
	}
	return true;
}

void Hackware::SetDupliGuess()
{
	for (size_t j = 0; j < UserGuess.size(); ++j)
	{
		PrevUserGuess.push_back(UserGuess[j]);
	}
}

bool Hackware::CheckDupliDigits()
{
	for (size_t j = 0; j < UserGuess.size(); ++j)
	{
		if (j == 0) {
		}
		else {
			if (UserGuess[j] == UserGuess[j - 1])
			{
				return true;
			}
		}
	}
	return false;
}
