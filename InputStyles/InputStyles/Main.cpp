#include <iostream>
#include <ctype.h>
#include <string>

void InputAsString()
{
	std::string userInput = "1234567890abc";
	for (size_t k = 0; k < userInput.size(); ++k)
	{
		char c = userInput[k];
		int isDigit = isdigit(c);
		std::cout << k << ": [" << c <<
			"], isDigit = " << (isDigit ? "true" : "false")
			<< ". ";
		if (isDigit)
		{
			int value = c - '0';
			std::cout << "Value = " << value;
		}
		std::cout << "\n";
	}
}

void InputAsInt()
{
	char c = 'a';
	if (!isdigit(c))
	{
		std::cout << "Not a digit\n";
	}
	else
	{
		std::cout << "Is a digit\n";
	}
	int userInput = 246801357;
	std::cout << userInput << std::endl;
	std::cout << "Digits are: ";
	while (userInput > 0)
	{
		int digit = userInput % 10;
		userInput /= 10;
		// use digit here
		std::cout << digit;
	}
	std::cout << std::endl;
}

void TestSizes()
{
	std::cout << "Sizeof(size_t)   = " << sizeof(size_t) << std::endl;
	std::cout << "Sizeof(unsigned) = " << sizeof(unsigned) << std::endl;
}

int main()
{
	TestSizes();
	InputAsInt();
	InputAsString();

	return 0;
}