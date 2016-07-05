#include <iostream>
using namespace std;



bool isBST(BinaryTreeNode<int>* root, int mins = INT_MIN,
		int maxs = INT_MAX) {
	if (root == NULL)
		return true;
	if (root->data < mins || root->data > maxs)
		return false;
	return isBST(root->left, mins, root->data) &&
		isBST(root->right, root->data, maxs);
}

BinaryTreeNode<int>* findLCA(BinaryTreeNode<int>* root, int a, int b) {
	if (root == NULL)
		return NULL;

	if (root->data == a || root->data == b) {
		return root;
	}

	BinaryTreeNode<int>* leftO = findLCA(root->left, a, b);
	BinaryTreeNode<int>* rightO = findLCA(root->right, a, b);
	if (leftO == NULL && rightO == NULL) {
		return NULL;
	}
	if (leftO != NULL) {
		return leftO;
	}

	if (rightO != NULL) {
		return rightO;
	} else {
		return root;
	}	
}

int main() {

}

