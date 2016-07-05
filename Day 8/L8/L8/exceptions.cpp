#include <iostream>
using namespace std;

string func1(int a) {
	if (a == 2) {
		return "abc";
	} else if (a == 3) {
		return "def";
	} else {
		throw "invalid input";
	}
}

int func2() {
	throw 100;
}


int func3() {

}

int main() {
	int i = 10;
	try {
		cout << func1(20) << endl;
		i = i + 5;
		cout << func2() << endl;
		i = i + 10;
	} catch(char const * str) {
		cout << str << endl;
		i = i + 20;
	} catch (int e) {
	}
	cout << i << endl;
	cout << func1(3) << endl;
}

