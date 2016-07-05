#include <iostream>
using namespace std;

int findMax(BinaryTreeNode<int>* root, bool caninclude = true) {
	if (root == NULL)
		return 0;

	if (!caninclude) {
		return findMax(root->left, true) + findMax(root->right, true);
	} else {
		int option1 = root->data +
			findMax(root->left, false) + findMax(root->right, false);
		int option2 = 
			findMax(root->left, true) + findMax(root->right, true);
		return max(option1, option2);
	}

}

int main() {

}

