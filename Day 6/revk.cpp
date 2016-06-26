#include <iostream>
#include <string>
//#include <conio.h>
using namespace std;

template <typename T>
class Node {
	public:
		T val;
		Node* next;

		Node(T val) {
			this->val = val;
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

void print(Node<int>* head) {
	while (head != NULL) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << -1 << endl;
}

int length(Node<int>* head) {
	if (head == NULL)
		return 0;
	return 1 + length(head->next);
}
Node<int>* revk(Node<int>* A,int k){
	Node<int>* cur=A;
	Node<int>* prev=NULL;
	Node<int>* next=NULL;
	int c=0;
	if(!A){
		return NULL;
	}
	int m=length(A);
	if(m<k){
		return A;
	}
	while(cur!=NULL&&c<k){
		next=cur->next;
		cur->next=prev;
		prev=cur;
		cur=next;
		c++;
	}
	if(next!=NULL)
		A->next=revk(next,k);
	return prev;
}
int main() {
	int k;
	cin>>k;
	Node<int>* head = takeLLInput();
	head=revk(head,k);
	print(head);
	delete head;
  //getch();

}
