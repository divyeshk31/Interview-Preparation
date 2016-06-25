#include <iostream>
using namespace std;



void printPerm(string input, string output) {
	if (input.size() == 0) {
		cout << output << endl;
		return;
	}
	for (int i = 0; i < input.size(); i++) {
		string remainingString = 
			input.substr(0, i) + input.substr(i+1, input.size() - 1 - i);
		printPerm(remainingString, output + input[i]);
	}
}

int main() {
	printPerm("abcd", "");
}

