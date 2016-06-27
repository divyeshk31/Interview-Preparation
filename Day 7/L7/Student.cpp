#include <iostream>
#include <vector>
using namespace std;

class Student {
	friend class ABC;
	public:
	char* name;
	vector<int>* assignments;
	const int rollNumber;
	Student(const Student & s):rollNumber(s.rollNumber) {
		this->assignments = new vector<int>();
		this->name = new char[strlen(s.name) + 1];
		strcpy(this->name, s.name);
	}

	Student(char* name) : rollNumber(1){
		assignments = new vector<int>();
		// this->name = name leads to student keeping pointer to passed array
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}

	int getRollNumber() const {
		return rollNumber;
	}

	void setName(char const * name) const {
		delete [] this->name;
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}

	~Student() {
		delete assignments;
		delete [] name;
	}

	private:
	int fees;
	friend int blah(Student & s);
};

int blah(Student & s) {
	cout << s.fees << endl;
	return 10;
}

class ABC {
	public:
	void print(Student & s) {
		cout << s.fees << endl;
	}
};

int main() {
	char a[] = "abcd";
	Student s(a);
	cout << s.name << endl;
	Student s2(s);

	Student s3 = s2;

	cout << s.name << endl;
	cout << s2.name << endl;

	s.name[1] = 'f';
	cout << s.name << endl;
	cout << s2.name << endl;

	ABC ab;
	ab.print(s);
	blah(s);
	a[0] = 'd';
	Student* sp = new Student(a);
	Student* sp2 = sp;
	cout << s.name << endl;
	cout << sp->name << endl;

	cout << s.rollNumber << endl;
}

