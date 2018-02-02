#include "Hackware.h"
#include <iostream>

int main()
{
	const int passwordLength = 4;
	const int numberOfTries  = 4;

	Hackware hack;
	std::vector<int> password = hack.CreatePassword(passwordLength);
	bool             result = hack.HackTerminal(password, numberOfTries);

	result;

	return 0;
}
