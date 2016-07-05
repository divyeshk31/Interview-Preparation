#include <bits/stdc++.h>
using namespace std;
template <typename T>
class stack {
	vector<T>* data;
	
	public:
	stack() {
		data = new vector<T>();
	}

	~stack() {
		delete data;
	}

	void push(T element) {
		data->push_back(element);
	}

	int size() {
		return data->size();
	}	

	T top() {
		if (size() == 0) {
			throw -1;
		}
		T output = data->at(data->size() - 1);
		return output;
	}

	T pop() {
		if (size() == 0) {
			throw -1;
		}
		T output = data->at(data->size() - 1);
		data->pop_back();
		return output;
	}

	bool isEmpty() {
		return size() == 0;
	}

};
