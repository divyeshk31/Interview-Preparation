#include <iostream>
using namespace std;

char findKth(char* str, int k) {
	int TotalLen = 0;
	int i = 0;
	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] < '0' || str[i] > '9') {
			TotalLen++;
		} else {
			TotalLen = TotalLen * (str[i] - '0');
		}
	}
	
	for (; i >=0 ;i--) {
		if (str[i] < '0' || str[i] > '9') {
			TotalLen--;
			if (TotalLen == k) {
				return str[i];
			}
		} {
			TotalLen = TotalLen/(str[i] - '0');
			k = k % TotalLen;
		}
	}



}

int main() {

}

