#include <iostream>
using namespace std;

int lcis(int* a, int*b, int size1, int size2, 
		int i, int j,int last, unordered_map<int, int>*** dp) {
	if (i >= size1 || j >= size2) {
		return 0;
	}

	if (dp[i][j] && dp[i][j]->count(last) > 0) {
		return dp[i][j]->at(last);
	}
// recursive calls

	if (!dp[i][j])
		dp[i][j] = new unordered_map<int, int>();
	
	dp[i][j]->put(last, answer);
	return answer;
}

int lcis(int* a, int* b, int size1, int size2,
		int last = INT_MIN) {
	if (size1 == 0 || size2 == 0)
		return 0;

	if (a[0] == b[0]) {
		int option1 = lcis(a + 1, b + 1, size1 - 1, size2 -1, last);
		if (a[0] > last) {
			int option2 = 
				1 + lcis(a + 1, b + 1, size1 - 1, size2 -1,a[0]);
			return max(option1, option2);
		}
		return option1;
	} else {
		int option1 = lcis(a + 1, b, size1 - 1, size2, last);
		int option2 = lcis(a, b + 1, size1, size2 - 1, last);
		return max(option1, option2);
	}
}


int main() {
	int a[] = {5,4,2,3,9,7,8,10};
	int b[] = {5,4,8,2,1,4,9,10};
	cout << lcis(a,b,8,8);
}

