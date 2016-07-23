#include <iostream>
using namespace std;

int BoyerMoore(char* s, char* t) {
	int m = strlen(s);
	int n = strlen(t);

	int last_index[256];
	for (int i = 0; i < 256; i++) {
		last_index[i] = -1;
	}

	for (int i = 0; t[i] != '\0'; i++) {
		last_index[t[i]] = i;	
	}

	for (int i = 0; i <= m - n; ) {
		int j = n - 1;
		for (; j >= 0; j--) {
			if (t[j] != s[i + j]) {
				char unmatchedChar = s[i + j];
				int li = last_index[unmatchedChar];
				if (li == -1) {
					i = i + j + 1;
				} else {
					if (li < j) 
						i = i + j - li;
					else 
						i++;
				}
				break;
			} 
		}
		if (j == -1) {
			return i;
		}
	}
	return -1;
}

int main() {
	char s[] = "this is a test string";
	char t[] = "strg";
	cout << BoyerMoore(s,t);
}

