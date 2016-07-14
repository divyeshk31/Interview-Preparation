#include <iostream>
#include <stack>
using namespace std;

class BinaryTreeNode {
	public:
		int data;
		BinaryTreeNode* left;
		BinaryTreeNode* right;
};

void sumofPair(BinaryTreeNode* root) {
	stack<BinaryTreeNode*> s;
	stack<BinaryTreeNode*> revs;
	bool lastActionPushS = true;
	bool lastActionPushRev = true;
	s.push(root);
	revs.push(root);
	bool updateInorder = true;
	bool updateRev = true;
	int currentInorderN = 0;
	int currentRevN = 1;
	while (currentRevN > currentInorderN) {
		if (updateInorder) {
			BinaryTreeNode* first = s.top();
			while (first->left && lastActionPushS) {
				s.push(first->left);
				lastActionPushS = true;
				first = first->left;
			}
			currentInorderN = first->data;
			s.pop();
			lastActionPushS = false;
			if (first->right) {
				s.push(first->right);
				lastActionPushS = true;
			}
		}

		if (updateRev) {
			BinaryTreeNode* first = revs.top();
			while (first->right && lastActionPushRev) {
				revs.push(first->right);
				lastActionPushRev = true;
				first = first->right;
			}
			currentRevN = first->data;
			revs.pop();
			lastActionPushRev = false;
			if (first->left) {
				revs.push(first->left);
				lastActionPushRev = true;
			}
		}

		if (currentInorderN + currentRevN == 0) {
			cout << currentInorderN << " " << currentRevN << endl;
			updateInorder = true;
			updateRev = true;
		} else if (currentInorderN + currentRevN > 0) {
			updateInorder = true;
			updateRev = false;
		} else {
			updateRev = true;
			updateInorder = false;
		}
	}
}

void inorder(BinaryTreeNode* root) {
	stack<BinaryTreeNode*> s;
	s.push(root);
	bool lastActionPush = true;
	while (!s.empty()) {
		BinaryTreeNode* first = s.top();
		if (first->left && lastActionPush) {
			s.push(first->left);
			lastActionPush = true;
		} else {
			cout << first->data << endl;
			s.pop();
			lastActionPush = false;
			if (first->right) {
				s.push(first->right);
				lastActionPush = true;
			}
		}
	}
}

int main() {
	
}
