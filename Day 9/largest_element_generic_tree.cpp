#include <iostream>
#include <vector>
//#include <conio.h>
#include <queue>
//#include <climits>
using namespace std;
int max(int a, int b){
	return (a>b?a:b);
}
template <typename T>
class TreeNode {
	T data;
	vector<TreeNode*> children;
	public:
	TreeNode(T data) {
		this->data = data;
	}

	~TreeNode() {
		for (int i = 0; i < children.size(); i++) {
			delete children.at(i);
		}
	}

	T getData() {
		return data;
	}

	void setData(T data) {
		this->data = data;
	}

	void setChild(int i, TreeNode* child) {
		if (i > children.size()) {
			throw "Out of bound";
		}
		children[i] = child;
	}

	void addChild(TreeNode* child) {
		children.push_back(child);
	}

	int numChildren() {
		return children.size();
	}

	TreeNode* getChild(int i) {
		if (i > children.size() - 1) {
			throw "Out of bound";
		}
		return children.at(i);
	}
};

TreeNode<int>* takeTreeInput() {
	int rootData;
	//cout << "Enter root data" << endl;
	cin >> rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);
	int numChildren;
	//cout << "Enter number of children " << endl;
	cin >> numChildren;
	for (int i = 0; i < numChildren; i++) {
		root->addChild(takeTreeInput());
	}
	return root;
}

int height(TreeNode<int>* root) {
	int maxChildHeight = 0;
	for (int i = 0; i < root->numChildren(); i++) {
		maxChildHeight = 
			max(maxChildHeight, height(root->getChild(i)));
	}
	return 1 + maxChildHeight;
}

TreeNode<int>* takeInputLWise() {
	int rootData;
	//cout << "Enter root data" << endl;
	cin >> rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);
	queue<TreeNode<int>*> queue;
	queue.push(root);
	while (!queue.empty()) {
		TreeNode<int>* first = queue.front();
		queue.pop();
		//cout << "Enter num children for " << first->getData() << endl;
		int numChild;
		cin >> numChild;
		for (int i = 0; i < numChild; i++) {
			//cout << "Enter " << i << "th child of " << first->getData() << endl;
			int childData;
			cin >> childData;
			TreeNode<int>* child = new TreeNode<int>(childData);
			queue.push(child);
			first->addChild(child);
		}
	}
	return root;
}

int large(TreeNode<int>* root){
	int max1=root->getData();
	for ( int i=0; i < root->numChildren() ; i++)
	{
		max1= max(max1, large(root->getChild(i)));
	}
	return max1;
}
void print(TreeNode<int>* root) {
	cout << root->getData() << ":";
	for (int i = 0; i < root->numChildren(); i++) {
		cout << root->getChild(i)->getData() << ",";
	}
	cout << endl;
	for (int i = 0; i < root->numChildren(); i++) {
		print(root->getChild(i));
	}
}

int main() {
	TreeNode<int>* root = takeInputLWise();
	int ans=large(root);
	cout<<ans<<endl;
	//print(root);
	//getch();
	delete root;
}

