#include "StringFuncs.h"
#include <iostream>
#include <string>

bool StringFuncs::StringsAreEqual(const char* const str1, const char* const str2)
{
	const char* str3 = str1;
	const char* str4 = str2;

	if (str1 == 0 && str2 == 0) {
		return true;
	}
	if (StringLen(str1) != StringLen(str2))
	{
		return false;
	}
	else
	{
		for (int k = 0; k < StringLen(str1); ++k)
		{
			if (*str3 != *str4)
			{
				return false;
			}
			++str3;
			++str4;
		}
		return true;
	}
}

bool StringFuncs::IsPalindrome(const char * const str)
{
	const char* str1 = str;
	const char* str2 = str;
	str2 += StringLen(str) - 1;
	if (*str == 0)
	{
		return true;
	}
	for (int k = 0; k < StringLen(str); ++k)
	{
		if (*str1 == *str2)
		{
			if (str2 == str)
			{
				return true;
			}
		}
		++str1;
		--str2;
	}
	return false;
}

int StringFuncs::StringCompare(const char * const str1, const char * const str2)
{
	bool done = false;
	const char* str3 = str1;
	const char* str4 = str2;

	if (!StringsAreEqual(str1, str2))
	{
		while (!done)
		{
			if (*str3 < *str4)
			{
				done = true;
				return -1;
			}
			else if (*str3 > *str4)
			{
				done = true;
				return 1;
			}
			str3++;
			str4++;
		}
	}
	return 0;
}

int StringFuncs::StringLen(const char * const str)
{
	int numElems = 0;
	bool done = false;
	const char* str1 = str;
	if (str == nullptr || *str == 0) return numElems;
	if (*str != 0)
	{
		while (!done)
		{
			if (*str1 == 0)
			{
				done = true;
			}
			else {
				++numElems;
				++str1;
			}
		}
	}
	return numElems;
}

int StringFuncs::FindSubString(const char * const source, const char * const target)
{
	int corIndex = 0;
	const char* str = source;
	const char* str1 = target;
	int length = StringLen(source);

	for (int k = 0; k < length; ++k)
	{
		while (*str == *str1 && corIndex < StringLen(target))
		{
			++k;
			++str;
			++str1;
			++corIndex;
		}
		if (corIndex == StringLen(target))
		{
			return  k - StringLen(target);
		}

		++str;
		corIndex = 0;
		str1 = target;
	}
	return -1;
}

char * StringFuncs::StringDup(const char * const str)
{
	char* str1 = new char[StringLen(str) + 1];
	StringCopy(str, str1, StringLen(str) + 1);
	return str1;
}

char * StringFuncs::StringReverse(char * const str)
{
	char* pBeg = str;
	char* pEnd = pBeg;
	int length = StringLen(str);
	pEnd += length - 1;
	for (int k = 0; k < length / 2; ++k)
	{
		char c = *pBeg;
		*pBeg = *pEnd;
		*pEnd = c;
		--pEnd;
		++pBeg;
	}
	return str;
}

char * StringFuncs::StringReverse(const char * const str)
{
	char* str1 = StringDup(str);
	return StringDup(StringReverse((char*)str1));;
}

char * StringFuncs::StringConcat(const char * const str1, const char * const str2, const char * sep)
{
	int length = StringLen(str1) + StringLen(str2) + StringLen(sep) + 1;
	const char* str1Copy = str1;
	const char* str2Copy = str2;
	const char* sepCopy = sep;
	char* combinedString = new char[length];
	char* copyComString = combinedString;
	for (int k = 0; k < StringLen(str1); ++k)
	{
		*combinedString = *str1Copy;
		++combinedString;
		++str1Copy;
	}
	if (*sepCopy != 0)
	{
		for (int l = 0; l < StringLen(sep); ++l)
		{
			*combinedString = *sepCopy;
			++combinedString;
			++sepCopy;
		}
	}
	for (int m = 0; m < StringLen(str2); ++m)
	{
		*combinedString = *str2Copy;
		++combinedString;
		++str2Copy;
	}
	*combinedString = 0;
return copyComString;
}

char * StringFuncs::ToLower(char * const str)
{
	char* str1 = str;
	int length = StringLen(str);
	for (int k = 0; k < length; ++k)
	{
		if (*str1 >= 'A' && *str1 < 'a')
		{
			*str1 += 32;
		}
		++str1;
	}
	return str;
}

char * StringFuncs::ToLower(const char * const str)
{
	char* str1 = StringDup(str);
	return ToLower(str1);
}

int StringFuncs::StringCopy(const char * const source, char* const target, int targetSize)
{
	const char* str1 = source;
	char* str2 = target;
	int numCopy = 0;
	if (*source != 0)
	{
		for (int k = 0; k < targetSize - 1; ++k)
		{
			if (*str1 == 0) {
				break;
			}
			++numCopy;
			*str2 = *str1;
			++str1;
			++str2;
		}
	}
	*str2 = 0;
	return numCopy;
}
