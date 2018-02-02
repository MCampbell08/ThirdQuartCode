#include "Calculator.h"
#include <iostream>
#include <math.h>
#include <string>
#include <vector>

Calculator::Calculator()
{
}


Calculator::~Calculator()
{
}

void Calculator::Execute01()
{
	std::cout << "Calculator v1.00, ready...\n";
	std::cout << "Enter and expression (use +, -):";
	int lval = 0;
	int rval = 0;
	char op = '?';
	int result = 0;
	
	std::cin >> lval >> op >> rval;
	if (op == '+')
	{
		result = lval + rval;
	}
	else if (op == '-')
	{
		result = lval - rval;
	}
	std::cout << "Result: " << result << "\n";
	std::cout << "Calculator done!\n";
}

void Calculator::Execute02()
{
	std::cout << "Calculator v2.00, ready...\n";
	std::cout << "Enter and expression (use +, -, *, /):";
	int lval = 0;
	int rval = 0;
	char op = '?';
	int result = 0;

	std::cin >> lval >> op >> rval;
	switch (op)
	{
	case '+': result = lval + rval;
		break;
	case '-': result = lval - rval;
		break;
	case '*': result = lval * rval;
		break;
	case '/': result = lval / rval;
		break;
	default:
		std::cout << "ERROR: Unknown Operator!\n";
	}
	std::cout << "Result: " << result << "\n";
	std::cout << "Calculator done!\n";
}

void Calculator::Execute03()
{
	std::cout << "Calculator v3.00, ready...\n";
	std::cout << "Enter and expression (use +, -, *, /):";
	int lval = 0;
	int rval = 0;

	std::cin >> lval;
	if (!std::cin) std::cout << "ERROR: No first operand!\n";

	for (char op; std::cin >> op;)
	{
		if (op != '=') std::cin >> rval;
		if (!std::cin) std::cout << "ERROR: No second operand!\n";
		switch (op)
		{
		case '+': lval += rval;
			break;
		case '-': lval -= rval;
			break;
		case '*': lval *= rval;
			break;
		case '/': lval /= rval; // TODO: Check for 0
			break;
		case '=': 
			std::cout << "Result: " << lval << std::endl;
			std::cout << "Calculator done!\n";
			return;
		default:
			std::cout << "ERROR: Unknown Operator!\n";
		}
	}
}

void Calculator::Execute04()
{
	bool exit = false;
	std::cout << "Calculator v4.00, ready...\n";
	double lval = 0;
	double rval = 0;

	while (!exit)
	{
		std::cout << "Enter an expression (use +, -, *, /, ^, 0x to Exit):";
		std::cin >> lval;
		if (!std::cin) {
			std::cout << "ERROR: No first operand!\n";
		}
		for (char op; std::cin >> op;)
		{
			if (op == 'x') {
				exit = true;

				break;
			}
			if (op != '=') std::cin >> rval;
			if (!std::cin) std::cout << "ERROR: No second operand!\n";
			switch (op)
			{
			case '+': lval += rval;
				break;
			case '-': lval -= rval;
				break;
			case '*': lval *= rval;
				break;
			case '/':
				if (rval == 0)
				{
					std::cout <<"ERROR: Cannot divide by 0!" << std::endl;
					std::cout << "Setting Result to zero!" << std::endl;
					lval = 0;
				}
				else 
				{
					lval /= rval;
				}
				break;
			case '^':lval = pow(lval, rval);
				break;
			case '=':
				std::cout << "Result: " << lval << std::endl;
				break;
			case 'x': 
			   exit = true;
			default:
				std::cout << "ERROR: Unknown Operator!\n";
			}
		}
	}
	std::cout << "Calculator done!\n";
}
