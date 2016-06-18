#include <iostream>
#include <unordered_map>
using namespace std;

void printIntersectionWithDups(int* a, int* b, int sizea, int sizeb) {
	unordered_map<int, int> map;
	for (int i = 0; i < sizea; i++) {
		map[a[i]] = map[a[i]] + 1;
	}

	for (int i = 0; i < sizeb; i++) {
		if (map.count(b[i]) == 1) {
			if (map[b[i]] > 0) {
				cout << b[i] << endl;
				map[b[i]] = map[b[i]] - 1;
			}
		}
	}

}

void printIntersection(int* a, int* b, int sizea, int sizeb) {
	unordered_map<int, bool> map;
	for (int i = 0; i < sizea; i++) {
		map[a[i]] = true;
	}

	for (int i = 0; i < sizeb; i++) {
		if (map.count(b[i]) == 1) {
			cout << b[i] << endl;
		}
	}
}

int main() {
	int dd[] = {10,30,20,10,30};
	int e[] = {20,10,7,6,30,10,7,10,9 , 20};
	printIntersectionWithDups(dd,e, 5, 10);
	return 0;
	int b[] = {10,5,6,2,1,134,34};
	int c[] = {1,4,5,134,10,35};
	printIntersection(b,c,7,6);

	unordered_map<int, int> freq;
	int a[] = {10,12,15,12,123,11,10,10};
	int output = -1;
	int max_freq = -1;
	for (int i = 0; i < 8; i++) {
		if(freq.count(a[i]) == 0) {
			freq[a[i]] = 1;
		} else {
			freq[a[i]] = freq[a[i]] + 1;
		}
		if (freq[a[i]] > max_freq) {
			max_freq = freq[a[i]];
			output = a[i];
		}
	}

	pair<int, int> p;
	p.first = 10000222;
	p.second = 1;
	freq.insert(p);
	cout << 10000222 << " : ";
	cout << freq.at(10000222) << endl;

	cout << output << endl;
	cout << freq.count(100233) << endl;	
	int jj = freq.at(100233);
	int d = freq[100233];
	cout << freq.count(100233) << endl;	
	cout << freq[100233] << endl;
	cout << d << endl;

}

