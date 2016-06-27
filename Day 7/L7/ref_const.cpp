#include <iostream>
using namespace std;

int increment(const int & a) {
//	int& b = a;
//	b++;
	return a + 1;
}

int main() {

	const int aconst = 10003;
	int absds = aconst;

	int * const p23 = &absds;
	int* p4 = p23;

	int const * p = &absds;
	// int * p3 = p;

	int abs = 10;
	int * const cp = &abs;

	int const * pc = &abs;
	//(*pc)++;
	int assdds = 100;
	pc = &assdds;

	int const * const cpc = &abs;

	const int aggg = 13;
	//int * p = &aggg;
	int const * p = &aggg;

	int a11 = 100;
	
//	p = &a11;
	(*p)++;

	const int a1 = 10;
	int a = 10;
	
	const int& b = a;

	const int& c = b;

//	int& d = c;

	a++;
	//b++;
	cout << a << endl;
	cout << b << endl;

	//int& b;
	//b = a;
}

