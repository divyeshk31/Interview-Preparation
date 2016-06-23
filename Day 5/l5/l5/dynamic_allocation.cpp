#include <iostream>
#include <vector>
using namespace std;

int* f1() {
	int i = 10;
	int* x = new int;
	return x;
}

int main() {
	int i;
	int* p = new int;
	(*p)++;
	delete p;

	cin >> i;
	int* a = new int[i];
	delete [] a;

	vector<int> v;
	vector<int>* vp = new vector<int>();

	i++;
	cout << i << endl;
}

