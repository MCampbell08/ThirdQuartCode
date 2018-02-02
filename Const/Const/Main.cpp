#include <iostream>

int OnBirthday(int age)
{
	++age;
	//update the database
	return age;
}

int OnBirthday2(int age) // Don't change variable being passed in unless intended to do so.
{
	int newAge = age + 1;
	//update the database
	return newAge;
}

int OnBirthday3(const int age) // Prevents from changing age.
{
	int newAge = age + 1;
	//update the database
	return newAge;
}

/*	v	CONST CORRECTNESS!	v	*/

void Func1(char *str)
{
	printf("Before [%s]\n", str);
	*str = 'x';                                                                                      
	++str;
	*str = 'z';
	printf("Before [%s]\n", str);
}

void Func2(const char *str) // string pointer to const char
{
	printf("Before [%s]\n", str);
	//*str = 'x';
	++str;
	//*str = 'z';
	printf("Before [%s]\n", str);
}

void Func3(char* const str) // Const string pointer to char
{
	printf("Before [%s]\n", str);
	*str = 'x';
	//++str;
	*str = 'z';
	printf("Before [%s]\n", str);
}

void Func4(const char* const str) // Const string pointer to const char
{
	printf("Size = %d\n", sizeof(str));
	printf("Before [%s]\n", str);
	//*str = 'x';
	//++str;
	//*str = 'z';
	printf("Before [%s]\n", str);
}

int main()
{
	printf("Hello, from Const!\n");
	char myString[] = "aeiou";
	Func4(myString);
	printf("Done!\n");
	return 0;
}