#include "Input.h"
#include "LinkedList.h"
#include "StringFuncs.h"
#include <iostream>
#include <string>
	
void Input::ProcessInput()
{
	LinkedList* list = new LinkedList();

	std::cout << "Enter words for them to be sorted; 'x' to quit:";

	std::string userInput;
	char exit[] = "x";

	while (std::cin >> userInput)
	{
		const char* separateWord = userInput.c_str();
		if (StringFuncs::StringsAreEqual(separateWord, exit))
		{
			std::cout << *list;
			break;
		}
		else
		{
			char * dup = StringFuncs::StringDup(separateWord);
			list->Add(dup);
		}
	}
	delete list;
}