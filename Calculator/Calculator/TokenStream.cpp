#include "TokenStream.h"
#include <iostream>
#include <assert.h>

TokenStream::TokenStream()
{
}


TokenStream::~TokenStream()
{
}

Token TokenStream::GetToken()
{
	if (isFull)
	{
		isFull = false;
		return buffer;
	}
	char ch;
	std::cin >> ch;
	switch (ch)
	{
	case '=':  // display result
	case 'q':  // exit Calculator
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case '^':
	case '~':
	case '!':
	case 'L':
	case '[':
	case ']':
	case '(':
	case ')':
		return Token(ch);


	case '.': // in case typed .75 for example
	case '0':case '1':case '2':case '3':case '4':
	case '5':case '6':case '7':case '8':case '9':
	{
		std::cin.putback(ch);
		double value;
		std::cin >> value;
		return Token('7', value);
	}
	case '{':
	{
		while (std::cin >> ch)
		{
			if (ch == '}') return GetToken();
		}
	}
	default:
		std::cout << "ERROR: Bad token found [" << (int)ch << "]\n";
		assert(false);
	}
	return Token();
}

bool TokenStream::PutTokenBack(Token t)
{
	if (isFull)
	{
		std::cout << "ERROR: TokenStream buffer is already full\n";
		assert(false);
		return false;
	}
	buffer = t;
	isFull = true;
	return true;
}
