#include <iostream>

template <typename ValueType>
void Show(char name[], ValueType value, char msg[] = "")
{
	std::cout << name << " = " << value << "   " << msg << "\n";
}

template <typename ValueType>

void Show(char name[], ValueType* ptrAddr, char msg[] = "")
{
	std::cout << name << " = " << ptrAddr << ", *" << name << " : " << *ptrAddr << "   " << msg << "\n";
}

void Skip() { std::cout << "\n\n"; }

void GetCommandLineArguments(int argc, char* argv[])
{
	for (int k = 0; k < argc; ++k)
	{
		std::cout << "Arg[" << k << "] = {"
			<< argv[k] << "}\n";
	}
}
//
//int* FunMethod()
//{
//	int j = 223;
//	return &j;
//}

class Counter // this should be in Counter.h
{

public:
	Counter(int val = -1) 
		: val(val), id(++numCounters)
	{
		printf("Create (%d, %d)\n", id, val);
	}
	~Counter()
	{
		printf("Destruct (%d, %d)\n", id, val);
	}

	int		   val;
	int		   id;
	static int numCounters;

};

int Counter::numCounters = 0; // this should be in Counter.cpp

Counter longlived{ 101 };

void PlayWithPointers3()
{
	// [new] calls constructor
	Counter* pc1 = new Counter;
	Counter* pc2 = new Counter{ 202 };
	Counter* pc3 = new Counter[5];
	Counter* pc4 = new Counter[5]{ 303, 304 };

	// [delete] calls destructor
	delete[] pc4;
	delete[] pc3;
	delete   pc2;
	delete   pc1;
}

void PlayWithPointersToo()
{
	double dArray[] = { 1.1, 2.2, 3.3 };
	Show("dArray", dArray);
	std::cout << "type is " << typeid(dArray).name() << "\n";
	std::cout << "Size = " << sizeof(dArray) << "\n";
	int numElems = sizeof(dArray) / sizeof(dArray[0]);
	Show("numElems", numElems);
	for (int k = 0; k < numElems; ++k)
	{
		std::cout << "dArray [" << k << "] = " << dArray[k] << "\n";
	}
	for (double d : dArray)
	{
		std::cout << d << "\n";
	}
	/*for (char c : "Hello")
	{
		std::cout << c << "\n";
	}
	for each (char c in "Hellotoo")
	{
		std::cout << c << "\n";
	}*/
	Skip();

//	double *p0;			  //Show("p0", p0);
	double *p1 = nullptr; //Show("p1", p1);

	//[if(!p1)] == [if (p1 == nullptr)];
	//double dp = 4.6;
	//p1 = &dp;

	if (!p1) std::cout << "p1 is not a valit ptr!\n";
	else     std::cout << "p1 is a valid ptr!\n";
	if (p1) std::cout << "p1 is a valit ptr!\n";
	else    std::cout << "p1 is not a valid ptr!\n";
	Skip();

	double *p2 = new double; Show("p2", p2);
	double *p3 = new double{ 2.78 }; Show("p3", p3);
	double *p4 = new double[3];
	double *p5 = new double[3]{ 1.1, 2.2, 3.3 }; Show("p5", p5);
	double *p6 = new double[3]{ 1.1};			 Show("p6[1]", p6[1]);

	int nn = 2; //read from cin
	//double a7[nn];
	double *p7 = new double[nn];

//	double zzz = 3.45;
//	std::cout << zzz << "\n";
	{
//		std::cout << zzz << "\n";	   // Define Lifetime
		double myArray[10];
		myArray[5] = 3.4;
//		double zzz = 9.999;
	  //double *p3 = new double[100];  //Memory Leak. BAD!
	}
//	std::cout << zzz << "\n";
	//::cout << myArray[5] << "\n";    // Not existent

	//do work with ptrs

	delete[] p7;
	delete[] p6;
	delete[] p5;
	delete[] p4;
	delete   p3;
	delete   p2;
}

int main(int /*argc*/, char* /*argv[]*//*Or **argv*/)
{
	std::cout << "Hello from PointerFun!\n";
	//GetCommandLineArguments(argc, argv);
	PlayWithPointersToo();
	std::cout << "Done!\n";
}

void PlayWithPointers()
{

	int v = 38;
	Show("v", v, "test msg");
	int * pv = &v;
	Show("pv", pv, "ptr to v");
	Skip();

	int w = *pv;
	int *px = pv;
	Show("w", w);

	*pv = 22;

	Show("v", v, "Modified v via pv");
	Show("w", w);
	Show("px", px);
	Skip();

	double pi = 3.14;
	double* pPi = &pi;
	Show("pi", pi);
	Show("pPi", pPi);
	Skip();

	*pPi = 3.141;
	Show("pi", pi);
	Show("pPi", pPi);
	Skip();

	*pPi = 3.1415;
	Show("pi", pi);
	Show("pPi", pPi);
	Skip();


}