#include "Pointers.h"
#include <iostream>

int Pointers::StringLen(const char * cString)
{
	int size = sizeof(cString);

	return size;
}

int Pointers::StringCopy(const char * source, char * target, int targetSize)
{
	return 0;
}

int main()
{
	printf("StringLen Method: [%d]" , StringLen("Hello"));

	return 0;
}
