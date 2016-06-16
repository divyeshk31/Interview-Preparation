#include <iostream>
using namespace std;

int greater(int a[], int n) {
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int numGreater = 0;
		for (int j = i + 1; j < n; j++) {
			if (a[j] > a[i]) {
				numGreater++;
			}
		}
		ans += numGreater * fact(n - i - 1);
	}
	return ans;
}

int main() {

}
