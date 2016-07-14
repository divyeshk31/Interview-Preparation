#include <iostream>
using namespace std;

int fib(int n, int* output) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;

	if (output[n] > 0) {
		return output[n];
	}
	output[n] = fib(n - 1) + fib(n - 2);
	return output[n];
}

int lcsDPI(char* s, char* t) {
	int m = strlen(s);
	int n = strlen(t);
	
	int** dp = new int*[m + 1];
	for (int i = 0; i < m + 1; i++) {
		dp[i] = new int[n + 1];
		for (int j = 0; j < n + 1; j++) {
			if (i == 0 || j == 0)
				dp[i][j] = 0;
			else 
				dp[i][j] = -1;
		}
	}

	for (int i = 1; i < m + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (s[m - i] == t[n - j]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
			} else {
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}
	// deallocate
	for (int i = 0; i < m + 1; i++) {
		delete [] dp[i];
	}
	delete [] dp;
	return dp[m][n];
}

int lcsDP(char* s, char* t, int** output, int slen, int tlen) {
	if (s[0] == '\0' || t[0] == '\0') {
		return 0;
	}

	if (output[slen][tlen] > -1) {
		return output[slen][tlen];
	}
	int ans;
	if (s[0] == t[0]) {
		ans = 1 + lcsDP(s + 1, t + 1, output, slen - 1, tlen - 1);
	} else {
		ans = max(lcsDP(s + 1, t, output, slen - 1, tlen), 
				lcsDP(s, t + 1, output, slen, tlen - 1));
	}

	output[slen][tlen] = ans;
	return ans;
}

int lcs(char* s, char* t) {
	if (s[0] == '\0' || t[0] == '\0') {
		return 0;
	}
	if (s[0] == t[0]) {
		return 1 + lcs(s + 1, t + 1);
	} else {
		return max(lcs(s + 1, t), lcs(s, t + 1));
	}
}

int main() {
	int n;
	cin >> n;
	int* output = new int[n + 1];
	cout << fib(n, output) << endl;
}

