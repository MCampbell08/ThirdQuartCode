#include "Calculator.h"
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <assert.h>
#include <iomanip>

/*
Expression:
(Term)
Expression '+' (Term)
Expression '-' (Term)

Term:
(Primary)
Term '*' (Primary)
Term '/' (Primary)
Term '%' (Primary) fmod(blah, blah)

Func:
Primary
Func '^' Primary
Func '~' Primary
Number 'L'


Primary:
Number '!'
(Number)
Term '(' Expression ')'

Number:
Floating point literal
*/

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
	Token t{ '+' };
	std::cout << t.value << std::endl;
	bool exit = false;
	std::cout << "Calculator v4.00, ready...\n";
	double lval = 0;
	double rval = 0;
	std::vector<double> results;

	while (!exit)
	{
		std::cout << "Enter an expression (use +, -, *, /, ^, 0x to Exit):";
		std::cin >> lval;
		if (!std::cin) {
			std::cout << "ERROR: No first operand!\n";
		}
		for (char op; std::cin >> op;)
		{
			if (op != '=') {
				if (op != 'x') {
					std::cin >> rval;
				}
				else if (op == 'x') {
					
					exit = true;
				}
			}
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
					std::cout <<	"ERROR: Cannot divide by 0!" << std::endl;
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

void Calculator::Execute05()
{
	std::cout << "Calculator v6.00, ready...\n";
	Calculate5();
	std::cout << "Calculator done!\n";
}

void Calculator::Calculate5()
{
	while (Statement())
	{

	}
}

bool Calculator::Statement()
{
	static double result = 0.0;
	Token t = GetToken();
	switch (t.kind)
	{
	case 'q': if (result != 0) ShowResult(result); return false;
	case '=': ShowResult  (result); result = 0.0;  break;
	default:  
		if (!tokens.empty())
		{
			ShowResult(result); result = 0.0; break;
		}
		else {
			PutTokenBack(t); break;
		}
	}
	result = Expression();
	return true;
}



double Calculator::Expression()
{
	double left = Term();
	for (;;)
	{
		Token  t = GetToken();
		switch (t.kind)
		{
		case '+': left += Term(); break;
		case '-': left -= Term(); break;
		
		default: PutTokenBack(t); return left;
		}
	}
	//return 0.0;
}

double Calculator::Term()
{
	double left = Func();
	for (;;)
	{
		Token  t = GetToken();
		switch (t.kind)
		{
		case '*': left *= Func();            break;
		case '/': left /= Func();            break;
		case '%': left = fmod(left, Func()); break;
		default: PutTokenBack(t);            return left;
		}
	}
	//return 0.0;
}

double Calculator::Func()
{
	double left = Primary();
	for (;;)
	{
		Token  t = GetToken();
		Store(t);
		switch (t.kind)
		{
		case 'L': left = log10(left);		    break;
		case '!': left = Factorial(left);       break;
		case '^': left = pow (left, Func());    break;
		case '~': left = Root(left, Primary()); break;
		default: PutTokenBack(t); return left;
		}
	}
	//return 0.0;
}

double Calculator::Primary()
{
	Token t = GetToken();
	Store(t);
	switch (t.kind)
	{
	case '7': return t.value;

	case '+':
	{
		return Primary();
	}
	case '-':
	{
		return -Primary();
	}
	case '[':
		{
			double d = Expression ();
			t = GetToken();
			Store(t);
			d = abs(d);
			if (t.kind != ']')
			{
				std::cout << "ERROR: Expected close bracket!\n";
				assert(false);
				return 0;
			}
			return d;
		}
	case '(': 
		{
			double d = Expression ();
			t = GetToken();
			if (t.kind != ')')
			{
				std::cout << "ERROR: Expected close parenthesis!\n";
				assert(false);
				return 0;
			}
			return d;
		}
	default:
		PutTokenBack(t);
		//std::cout << "ERROR: Expected an expression!\n";
		break;
	}
	return 0.0;
}

Token Calculator::GetToken()
{
	return tokenStream.GetToken();
}

void Calculator::PutTokenBack(Token t)
{
	tokenStream.PutTokenBack(t);
}

void Calculator::ShowResult(double result)
{	
	if (tokens.back().kind == '=')
	{
		std::cout << "==>" << std::setw(10) << result << " : ";
	}
	else
	{
		std::cout << "?=>" << std::setw(10) << result << " : ";
	}

	for (int j = 0; j < tokens.size(); ++j)
	{
		if (tokens[j].kind == '7')
		{
			std::cout << tokens[j].value;
		}
		else
		{
			std::cout << tokens[j].kind;
		}
	}
	std::cout << std::endl;
	ClearStorage();
}

double Calculator::Root(double value, double power)
{
	if (power == 0)
	{
		std::cout << "ERROR: Expected Power Greater than 0!\n";
		assert(false);
		return 0;
	}
	else 
	{
		return pow(value, 1.0 / power);
	}
	
}

double Calculator::Factorial(double value)
{
	double totalValue = 0;
	if (value > 0) {
		double integerNum = floor(value);
		totalValue = integerNum;
		for (double j = integerNum; j > 0; --j)
		{
			if (j == 1)
			{
				break;
			}
			else
			{
				totalValue *= integerNum - 1;
				integerNum--;
			}
		}
	}
	else if (value < 0)
	{
		double integerNum = floor(value);
		integerNum = abs(integerNum);
		totalValue = integerNum;
		for (double j = integerNum; j > 0; --j)
		{
			if (j == 1)
			{
				break;
			}
			else
			{
				totalValue *= integerNum - 1;
				integerNum--;
			}
		}
		totalValue *= -1;
	}
	return totalValue;
}

void Calculator::Store(Token t)
{
	tokens.push_back(t);
}

void Calculator::ClearStorage()
{
	tokens.clear();
}
