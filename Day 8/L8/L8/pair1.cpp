#include <iostream>
using namespace std;

class pair1{
	int x;
	int y;
	public:
	pair1() {

	}
	pair1(const pair1 & p) {
		x = p.x;
		y = p.y;
	}

	void print() {
		cout << x << endl;
		cout << y << endl;
	}

	static pair1* add(pair1 & p1, pair1 & p2) {
		cout << p1.x << endl;
		return NULL;
	}

};

int main() {
	pair1 p1;
	pair1 p2;
	p2.add(p1,p2);
	pair1::add(p1,p2);
}
