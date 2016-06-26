#include <bits/stdc++.h>
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

void print(Node<int>* head) {
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << -1 << endl;
}

int length(Node<int>* head) {
	if (head == NULL)
		return 0;
	return 1 + length(head->next);
}
void swap(Node<int>* a, Node<int>* b){
	int temp=a->data;
	a->data=b->data;
	b->data=temp;
}
void bubble(Node<int>* A){
	int flag;
	Node<int>* cur;
	Node<int>* ptr=NULL;
	if(cur==A)
		return;
do{
	flag=0;
	cur=A;
	while(cur->next!=ptr){
		if(cur->data>cur->next->data){
			swap(cur,cur->next);
			flag=1;
		}
		cur=cur->next;
	}
	ptr=cur;
}
	while(flag);
}
int main() {
	Node<int>* start= takeLLInput();
	bubble(start);
	print(start);
	delete start;
}