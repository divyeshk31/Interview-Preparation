#include <iostream>
using namespace std;
#include <set>

int main() {
	set<int> s;
	set<int>::iterator it;


	s.insert(10);
	s.insert(1);
	s.insert(100);
	s.insert(1000);
	s.insert(1100);
	s.insert(1200);
	cout << s.size() << endl;
	s.insert(100);
	cout << s.size() << endl;
	cout << s.count(100) << endl;
	cout << s.count(1100) << endl;

	it = s.find(100);
	it++;
	s.erase(it, s.end());
	if (it == s.end()) {
		cout << "not found" << endl;
	} else {
		cout << *it << endl;
		cout << "found" << endl;
	}

	it = s.begin();
	for (; it != s.end(); it++) {
		cout << *it << endl;		
	}

}

