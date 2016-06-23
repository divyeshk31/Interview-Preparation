#include <iostream>
using namespace std;

void increment(int a,int* i) {
	if(a == 0)
		return;
	i = i + 1;
	cout << a << " " <<i << endl;
	increment(a - 1, i);
	cout << a << " " <<i << endl;
}

void increment(int* i) {
	(*i)++;
	i = i + 1;
}

void incrementint(int& k) {
	k++;
}


int main() {
	int u = 10;
	incrementint(u);
	cout << u << endl;
	int * b = &u;
	cout << b << endl;
	increment(b);
	cout << b << endl;
	int a[3];
	cout << a << " " << &a << endl;
	cout << a + 1 << " " << &a + 1 << endl;
}

