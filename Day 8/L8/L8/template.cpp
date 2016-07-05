#include <iostream>
using namespace std;

class A {
	public :
		int getInt() {
			return 10;
		}
};

class B: public A {

};

class C: public A {

};

template <typename T, typename V>
class pair2 {
	public:
	T x;
	V y;
	pair2(T x, V y) {
		//x.getInt();
		A a = (A)x;
		this->x = x;
		this->y = y;
	}
};

/*
template <typename T>
void template_method() {
		cout << &a << endl;
}
*/

int main() {
	B b;
	C c;
	pair2<B, C> p(b,c);
	//template_method(p);
}

