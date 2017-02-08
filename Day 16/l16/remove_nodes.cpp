#include <iostream>
using namespace std;

class Node {
	public:
		int data;
		Node* next;
		Node(int data) {
			this->data = data;
			next = NULL;
		}
};

void removeNodes(Node* &root, Node* current, Node* prev,
		int sum, vector<Node*>& v) {
	if (sum == 0 && v.size() > 0) {
		for (int i = v.size() - 1; i>=0; i--) {
			Node* prev = v[i];
			if (prev != NULL) {
				prev->next = prev->next->next;
			} else {
				root = root->next;
			}
		}
		return;
	}

	if (current == NULL) {
		return;
	}

	v.push_back(prev);
	removeNodes(root, current->next, current, sum - current->data, 
			v);
	v.pop_back();
	removeNodes(root, current->next,current, sum, v);
}










bool isScrable(string s1, string s2) {
	if (s1.size() != s2.size()) {
		return false;
	}
	if (s1.size() == 0)
		return true;

	if (s1.size() == 1 && s1[0] == s2[0])
		return true;

	int length = s1.size()/2;
	bool option1 = 
		isScramble(s1.substr(0,length), s2.substr(0,length)) &&
		isScrable(s1.substr(length), s2.substr(length));
	bool option2 = 
		isScramble(s1.substr(0,length), s2.substr(s1.size() - length))
		&& 
		isScramble(s1.substr(length), s2.substr(0, s1.size() - length));
	return option1 || option2;
}

pair<int, int> cover2(TreeNode* root) {
	if (root == NULL) {
		return make_pair(0,0);
	}

	pair<int, int> leftans = cover2(root->left);
	pair<int, int> rightans = cover2(root->right);

	int answer1 = max(1 + leftans.first + rightans.first,
			leftans.second + rightans.second);
	int answer2 = 1 + leftans.first + rightans.first; 
	return make_pair(answer1, answer2);
}

int cover(TreeNode* root, bool upperEdgeCovered=true) {
	if (root == NULL)
		return 0;

	if (upperEdgeCovered) {
		int option1 = 
			1 + cover(root->left, true) +  cover(root->right, true);
		int option2 = 
			cover(root->left, false) + cover(root->right, false);
		return max(option1, option2);
	} else {
		return 1 + cover(root->left, true) +
			cover(root->right, true);
	}
}

int partitions(char* str, int cindex,int size, bool** palindrome,
		int* dp)
{
	if (dp[cindex] > 0)
		return dp[cindex];
	if (size == 1) {
		return 1;

	if (size == 0) {
		return 0;
	}

	int best = INT_MAX;
	for (int i = cindex; i < size; i++) {
		if (palindrome[cindex][i]) {
			int option = 
				1 + partitions(str, i + 1, size, palindrome, dp);
			if (option < best)
				best = option;
		}
	}
	dp[cindex] = best;
	return best;
}

void equalAvg(int* array, int size, vector<int>* taken, int sum, int avg) {
	if (sum/taken->size() == avg) {
		// print array
		return;
	}
	if (size == 0)
		return;

	equalAvg(array + 1, size - 1, taken, sum, avg);
	taken->push_back(array[0]);
	equalAvg(array + 1, size - 1, taken, sum + array[0], avg);
	taken->pop_back();
}

int knapsack(int* weights, int* values,
		int totalWeight, int size) {
	if (totalWeight <= 0) {
		return 0;
	}
	if (size == 0) {
		return 0;
	}
	
	int option1 = 0;
	if (weights[0] < totalWeight) {
		option1 = values[0] + knapsack(weights + 1, values + 1, 
				totalWeight - weights[0], size - 1);
	}
	option2 = knapsack(weights + 1, values + 1, totalWeight,
			size - 1);

	return max(option1, option2);
}

int main() {
	
}

