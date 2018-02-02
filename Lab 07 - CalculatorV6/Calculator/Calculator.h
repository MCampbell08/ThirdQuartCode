#pragma 
#include "Token.h"
#include "TokenStream.h"
#include <vector>

class Calculator
{
public:
	Calculator();
	~Calculator();

public:
	void Execute01 ();
	void Execute02 ();
	void Execute03 ();
	void Execute04 ();
	void Execute05 ();

private:
	void   Calculate5   ();
	bool   Statement    ();
	double Expression   ();
	double Term         ();
	double Func         ();
	double Primary      ();
	Token  GetToken     ();
	void   PutTokenBack (Token  t);
	void   ShowResult   (double result);
	double Root         (double value, double power);
	double Factorial    (double value);
	void   Store        (Token  t);
	void   ClearStorage ();
private:
	TokenStream tokenStream;
	std::vector <Token> tokens;
};

