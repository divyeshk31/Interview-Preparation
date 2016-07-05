#include <iostream>
#include <conio.h>
#include <climits>
#include <queue>
using namespace std;

template <typename T>
class BinaryTreeNode {
	public:
	T data;
	BinaryTreeNode* leftnode;
	BinaryTreeNode* rightnode;

	BinaryTreeNode(T data) {
		this->data = data;
		leftnode = NULL;
		rightnode = NULL;
	}

	~BinaryTreeNode() {
		if (leftnode)
			delete leftnode;

		if (rightnode)
			delete rightnode;
	}
};

int minimum(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		return INT_MAX;
	}
	int min1 = min(minimum(root->leftnode), minimum(root->rightnode));
	return min(min1, root->data);
}
int height(BinaryTreeNode<int>* root) {
	if (root == NULL)
		return 0;
	return 1 + max(height(root->leftnode), height(root->rightnode));

}
int diameter(BinaryTreeNode<int>* root) {
	if (root == NULL)
		return 0;

	int lh = height(root->leftnode);
	int rh = height(root->rightnode);
	int ld = diameter(root->leftnode);
	int rd = diameter(root->rightnode);
	return max(max(ld,rd), lh + rh);
}


int diameter(BinaryTreeNode<int>* root, int& height1) {
	if (root == NULL) {
		height1 = 0;
		return 0;
	}
	int leftHeight, rightHeight;
	int ld = diameter(root->leftnode, leftHeight);
	int rd = diameter(root->rightnode, rightHeight);
	height1 = 1 + max(leftHeight, rightHeight);
	return  max(max(ld, rd), leftHeight + rightHeight);
}

pair<int, int> heightDiameter(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		pair<int, int> p(0,0);
		return p;
	}

	pair<int, int> la = heightDiameter(root->leftnode);
	pair<int, int> ra = heightDiameter(root->rightnode);

	int height = 1 + max(la.first,ra.first);
	int diameter = 
		max(max(la.second, ra.second), la.first + ra.first);
	pair<int,int> output(height, diameter);
	return output;
}


BinaryTreeNode<int>* takeInputLWise() {
	int rootData;
	//cout << "Enter root data" << endl;
	cin >> rootData;
BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
	queue<BinaryTreeNode<int>*> q;
	q.push(root);
	while(!q.empty()){
			BinaryTreeNode<int>* top = q.front();
			//cout<<"Enter the first child of " + top->data;
			int left;
			cin>>left;
			if(left!=-1){
				BinaryTreeNode<int>* leftnode = new BinaryTreeNode<int>(left);
				leftnode->data = left;
				q.push(leftnode);
				top->leftnode= leftnode;
			}
			//cout<<"Enter the second child of "+ top->data;
			int right;
			cin>>right;
			if(right!=-1){
				BinaryTreeNode<int>* rightnode = new BinaryTreeNode<int>(right);
				rightnode->data = right;
				q.push(rightnode);
				top->rightnode= rightnode;
			}
		}
		return root;
	}


int main() {
	BinaryTreeNode<int>* root = takeInputLWise();
	int ans=height(root);
	cout<<ans<<endl;
	getch();
	delete root;
}