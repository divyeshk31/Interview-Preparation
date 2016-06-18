#include <iostream>
#include "mypair.h"
#include <unordered_map>
using namespace std;

void printPairs(int* a, int size) {
	unordered_map<int, int> map;
	for (int i = 0; i < size; i++) {
		if (map.count(-a[i]) == 1) {
			cout << a[i] << " " << -a[i] << endl;
		}
		map[a[i]] = 1;
	}
}

int main() {
	mypair<int, int*> p;
	unordered_map<string, int> map;
	map["abc"] = 10;
	int a = map["abc"];
	cout << map.size() << endl;
	int b = map["def"];
	cout << map.size() << endl;
	map["def"] = 10;
	cout << map.size() << endl;
	cout << a << endl;
	cout << b << endl;
}

