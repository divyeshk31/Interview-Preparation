#include <iostream>
using namespace std;

int pow(int x, int n) {
	if (n == 0)
		return 1;
	int smallerAnswer = pow(x, n/2);
	if (n % 2 == 0) {
		return smallerAnswer * smallerAnswer;
	} else {
		return smallerAnswer * smallerAnswer * x;
	}
}

string getString(int n) {
	if (n == 2) {
		return "abc";
	} 
	if (n == 3) {
		return "def";
	}
	if (n == 4) {
		return "ghi";
	}
	return " ";
}

void printCombinations(int input, string output) {
	if (input == 0) {
		cout << output << endl;
		return;
	}

	string lastDigitOption = getString(input % 10);
	for (int i = 0; i < lastDigitOption.size(); i++) {
		printCombinations(input/10, lastDigitOption[i] + output);
	}
}

vector<string>* getCombinations(int input) {
	if (input == 0) {
		vector<string>* output = new vector<string>();
		output->push_back("");
		return output;
	}
	vector<string>* smallerOutput = getCombinations(input/10);
	string lastDigitOption = getString(input % 10);	
	vector<string>* output = new vector<string>();

	for (int i = 0; i < smallerOutput->size(); i++) {
		for (int j = 0; j < lastDigitOption.size(); j++) {
			output->push_back(smallerOutput->at(i) + lastDigitOption[j]);
		}
	}
	delete smallerOutput;
	return output;
}	

void addStar(char* str) {
	if (str[0] == '\0' || str[1] == '\0') {
		return;
	}

	if (str[0] == str[1]) {
		
	}

}

int main() {

}
