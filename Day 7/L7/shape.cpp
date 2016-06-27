#include <iostream>
using namespace std;

class shape {
	int ai;
	protected:
	int bi;
	
	public:
		int c1;

		int getAi() {
			return ai;
		}

		virtual int a() {
			return 10;
		}	

		virtual int getArea() = 0;

};

class rect : public shape {

	// 

	public:

		int getArea() {
			return 10000;
		}

		int a() {
			return 100;
		}

		int b() {
			return 20;
		}

		int c() {
	return 30;
		}	

};

int main() {

	rect * rp = new rect();
	//shape * sp = new shape();
//	cout << sp->c1 << endl;
	shape * sp2 = new rect();

	sp2->getArea();

	int i;
	cin >> i;
	/*if (i == 1)
		sp2 = new rect();
	else 
		sp2 = new shape();
*/
//	cout << sp2->c1 << endl;

	cout << sp2->a() << endl;
	
	
	rect * rp2 = (rect *)sp2;
	cout << rp2->b() << endl;
	

	rect r;
	cout << r.c1;
	cout << r.a() << endl;

	cout << r.b() << endl;

}
