#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

void printVector(vector<int> v) {
	vector<int>::iterator it = v.begin();
	while (it != v.end()) {
		cout << *it << ",";
		it++;
	}
	cout << endl;
	/*it = v.end() - 1;
	while (it >= v.begin()) {
		cout << *it << ",";
		it--;
	}*/
}

class Student {
	public:
		int marks;
		int rollNumber;

		bool operator < (const Student s) {
			if (this->marks < s.marks) {
				return true;
			} else {
				return false;
			}
		}
};

class ComparisonClass {
	public:
	bool operator() (Student a, Student b) {
		return true;
	}
};

int main() {

	map<int, string> m;
	m[10] = "abc";
	pair<int, string> pair1(11, "abc");
	m.insert(pair1);



	priority_queue<int, vector<int>, greater<int> > pq2;


	priority_queue<Student, vector<Student>, ComparisonClass> pq;
	Student s1;
	Student s2;
	pq.push(s1);
	pq.push(s2);


	priority_queue<int> q;

	for (int i = 50; i >= 0; i = i - 10) {
		q.push(50 - i);
	}
	while (!q.empty()) {
		cout << q.top() << ",";
		q.pop();
	}
	cout << endl;

	int a[] = {1,2,3};
	vector<int> v1(a, a + 3);
	vector<int> v(2,3);
	printVector(v);	
}
