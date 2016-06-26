#include <iostream>
#include <string>
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

Node<int>* getNthNode(Node<int>* head, int n) {
	for (int i = 0; i < n;  i++) {
		head = head->next;
	}
	return head;
}

Node<int>* reverse(Node<int>* head) {
	Node<int>* prev=NULL;
	Node<int>* next;
	while(head!=NULL){
		next=head->next;
		head->next=prev;
		prev=head;
		head=next;
	}
	return prev;
}

int main() {
	Node<int>* head = takeLLInput();
	head = reverse(head);
	print(head);
	delete head;
}
