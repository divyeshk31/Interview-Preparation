#include <iostream>
#include <queue>
#include <stdlib.h>
#include <stdio.h>
//#include <conio.h>
using namespace std;
template <typename T>
class Node {
	public:
		T data;
		Node* next;

		Node(T data) {
			this->data = data;
			next = NULL;
		}

		~Node() {
			if (next)
				delete next;
		}
};

Node<int>* takeLLInput() {
	Node<int>* head = NULL;
	Node<int>* tail = NULL;

	int n;
	cin >> n;
	while (n != -1) {
		Node<int>* nextNode = new Node<int>(n);
		if (head == NULL) {
			head = nextNode;
			tail = nextNode;
		} else {
			tail->next = nextNode;
			tail = nextNode;
		}
		cin >> n;
	}
	return head;
}

struct node{
    int data;
    node *left;
    node *right;
};
node* getnewnode(int data)
{
    node *temp = new node();
    temp->data = data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
node* takeInputLWise(){
    int rootData;
    cin >> rootData;
    node *root = getnewnode(rootData);
    queue<node *> q;
    q.push(root);
    while(!q.empty())
    {
        node *top=q.front();
        q.pop();
        int child1,child2;
        cin>>child1>>child2;
        if(child1!=-1)
        {
            node *left = getnewnode(child1);
            q.push(left);
            top->left=left;
        }
        if(child2!=-1)
        {
            node *right = getnewnode(child2);
            q.push(right);
            top->right=right;
        }
    }
    return root;
}
node * MakeBST(Node<int>* &head, int s, int e){
	if(s>e) return NULL;
	int mid=(s+e)/2;
	node *leftchild=MakeBST(head, s, mid-1);
	node *root=getnewnode(head->data);
	root->left=leftchild;
	head=head->next;
	root->right=MakeBST(head, mid+1, e);
	return root;
}
int length(Node<int>* head){
	int count=0;
	Node<int>* cur=head;
	while(cur!=NULL){
		count++;
		cur=cur->next;
	}
	return count;
}
int height(node* root) {
    if (root == NULL)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

void printGivenLevel(struct node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);

    else if (level > 1)
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}

void printLevelOrder(node* root)
{
    int h = height(root);
    int i;
    for (i=1; i<=h; i++)
    {
        printGivenLevel(root, i);
        cout<<endl;
    }
}

int main()
{
    Node<int>* head = takeLLInput();
    int n=length(head);
    node *root = MakeBST(head,0,n-1);
    printLevelOrder(root);
    //getch();
    return 0;
}
