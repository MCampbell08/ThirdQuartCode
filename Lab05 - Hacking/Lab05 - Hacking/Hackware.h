#pragma once
#include <vector>
class Hackware
{
public:
	Hackware();
	~Hackware();

public:
	std::vector<int> CreatePassword  (int passwordLength = 4);
	bool             HackTerminal    (std::vector<int> password, int numberOfTries = 4);
	bool             DisplayCases    ();
	void             SetDupliGuess   ();
	bool			 CheckDupliDigits();
	
private:
	bool             hackingFinished = false;
	bool             InputAsString ();
	std::vector<int> UserGuess;
	std::vector<int> PrevUserGuess;
	std::vector<int> PasswordCharacters;
};

