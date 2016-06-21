#include <iostream>
#include <vector>
#include <string>
using namespace std;

void smallestSubstring(string s, string t) {
	int i = 0;
	int j = 0;
	int freq[256] = {0};
	int numberCharRequired = 0;
	for (int k = 0; k < t.size(); k++) {
		freq[t[k]]++;
		if (freq[t[k]] == 1) {
			numberCharRequired++;
		}
	}
	int bestLength = s.size() + 1;
	int index = -1;
	while (i < s.size() && j < s.size()) {		
		if (numberCharRequired > 0) {
			freq[s[j]]--;
			if (freq[s[j]] == 0) {
				numberCharRequired--;
			}
			j++;
		} else if (numberCharRequired == 0) {
			if (j - i < bestLength) {
				bestLength = j - i;
				index = i;
			}
			freq[s[i]]++;
			if (freq[s[i]] == 1) {
				numberCharRequired++;
			}
			i++;
		}
	}
	if (index == -1) {
		cout << "Nothing found" << endl;
		return;
	}
	cout << s.substr(index, bestLength) << endl;
}

void print_sum(int n, vector<int> &output, bool first = true) {
	if (n == 0) {
		for (int i = 0; i < output.size(); i++) {
			cout << output.at(i) << ",";
		}
		cout << endl;
		return;
	}
	int end;
	if (first)
		end = n - 1;
	else
		end = n;

	for (int i = 1; i <= end; i++) {
		output.push_back(i);
		print_sum(n - i, output, false);
		output.pop_back();
	}
}

int sum(int a[], int size) {
	if (size == 0) {
		return 0;
	}
	else return a[0] + sum(a + 1, size - 1);
}

void test(int a[]) {
	cout << sizeof(a) << endl;
}

int main() {
	int b[10];
	int *p = &b[0];
	cout << &p << endl;
	cout << &b << endl;
	cout << sizeof(b) << endl;
	cout << sizeof(p) << endl;
	test(b);
	vector<int> a;
	print_sum(4, a);
	smallestSubstring("this is a test string", "tist");
}
