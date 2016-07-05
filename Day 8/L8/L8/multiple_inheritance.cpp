#include <iostream>
using namespace std;

class Student {
	public:
		int x;
		Student(int x) {
			this->x = x;
		}

		int blah() {
			return 4;
		}	

};

class Teacher {
	public:
		int y;

		Teacher(int y) {
			this->y = y;
		}

		int blah() {
			return 4;
		}
};

class TA:public Student, public Teacher {
	public:
		TA(int x, int y):Teacher(y), Student(x){
		}
};

int main() {
 TA ta(1,2);
 cout << ta.x << endl;
 cout << ta.y << endl;
 cout << ta.blah() << endl;
}

