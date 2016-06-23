#include <bits/stdc++.h>
#include<conio.h>
using namespace std;

bool findPath(int** a, int m, int n, int x, int y, bool** b) {
	if (x < 0 || x >= m || y < 0 || y >=n || a[x][y] == 1 
			|| b[x][y]) {
		return false;
	}
	
	if (a[x][y] == 2) {
		return true;
	}
	b[x][y] = true;
	if (findPath(a, m, n, x + 1, y, b)) {
		return true;
	}
	if (findPath(a, m, n, x - 1, y, b)) {
		return true;
	}
	if (findPath(a, m, n, x , y + 1, b)) {
		return true;
	}
	if (findPath(a, m, n, x , y - 1, b)) {
		return true;
	}
	return false;
}

int main() {
	
}
