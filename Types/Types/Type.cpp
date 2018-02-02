#include <stdio.h>
#include <iostream>

void ShowIntInfo()
{
	std::cout << "Boolean Type" << std::endl;
	printf("Size of boolean = %d\n", sizeof(bool));
	std::cout << "\nTypes of Integers" << std::endl;
	printf("Size of char = %d\n", sizeof(char));
	printf("Size of short = %d\n", sizeof(short));
	printf("Size of int = %d\n", sizeof(int));
	printf("Size of long = %d\n", sizeof(long));
	printf("Size of long long = %d\n", sizeof(long long));
	std::cout << "\nSigned Types of Integers" << std::endl;
	printf("Size of char = %d\n", sizeof(signed char));
	printf("Size of short = %d\n", sizeof(signed short));
	printf("Size of int = %d\n", sizeof(signed int));
	printf("Size of long = %d\n", sizeof(signed long));
	printf("Size of long long = %d\n", sizeof(signed long long));
	std::cout << "\nUnsigned Types of Integers" << std::endl;
	printf("Size of char = %d\n", sizeof(unsigned char));
	printf("Size of short = %d\n", sizeof(unsigned short));
	printf("Size of int = %d\n", sizeof(unsigned int));
	printf("Size of long = %d\n", sizeof(unsigned long));
	printf("Size of long long = %d\n", sizeof(unsigned long long));
}

void ShowRealInfo()
{
	std::cout << "Types of Real Numbers" << std::endl;
	printf("Size of float = %d\n", sizeof(float));
	printf("Size of double = %d\n", sizeof(double));
	std::cout << "\nTypes of Long Version of Real Numbers" << std::endl;
	printf("Size of float = %d\n", sizeof(long float));
	printf("Size of double = %d\n", sizeof(long double));
}

int main () 
{
	printf("Here are listed types! \n");
	ShowIntInfo();
	ShowRealInfo();
}



