#include <iostream>
using namespace std;

int remove(int a[], int size) {
	int elementToBeChecked = 0;
	int availablePosition = 0;
	while (elementToBeChecked < size) {
		bool flag = false;
		for (int i = 0; i < elementToBeChecked; i++) {
			if (a[i] == a[elementToBeChecked]) {
				flag = true;
				break;
			}
		}
		if (flag) {
			elementToBeChecked++;
		} else {
			a[availablePosition] = a[elementToBeChecked];
			availablePosition++;
			elementToBeChecked++;
		}
	}
	return availablePosition;
}

int main() {
	char a[100];
	cin >> a;
	
	int freq[256] = {0};
	for (int i = 0; a[i] != '\0'; i++) {
		freq[a[i]]++;
	}




}

