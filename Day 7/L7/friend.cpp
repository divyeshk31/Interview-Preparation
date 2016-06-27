#include <iostream>
using namespace std;
class A {
	int a;
	friend class B;
};

class B {
	int b;

	int temp(A objA) {
		cout << objA.a << endl;
	}
}


int main() {

}

