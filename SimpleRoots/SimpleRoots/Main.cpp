#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <math.h>

const int beginningLoop = 0;
const int limit = 100;
const double loopAdder = 5.00;
const int precision = 4;
const float cubic = 0.3333;

void ShowSquareRoots()
{
	for (int j = beginningLoop; j <= limit; j+=loopAdder) 
	{
		double result = sqrt(j);
		printf("Sqrt(%3d) = %2.4f\n", j, result);
	}
	printf("------------------------\n\n");
}

void ShowCubeRoots()
{
	for (int j = beginningLoop; j <= limit; j += loopAdder)
	{
		double result = pow(j, cubic);
		std::cout << "Cubed Root(" << std::setw(3)  << j << ") = " << std::setprecision(precision) <<  result << std::endl;
	}
	std::cout << "------------------------\n\n" << std::endl;
}

void ShowFourthRoot() 
{
	const int buffersize = limit;
	char buffer[buffersize];
	for (int j = beginningLoop; j <= limit; j += loopAdder)
	{
		double result = sqrt(sqrt(j));
		sprintf_s(buffer, buffersize, "Fourth Root(%*d) = %2.*f\n", precision, j, precision, result);
		std::cout << buffer;
	}
}

int main()
{
	ShowSquareRoots();
	ShowCubeRoots();
	ShowFourthRoot();
}