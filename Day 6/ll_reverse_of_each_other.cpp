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
Node<int>* reverse(Node<int>* head) {
	if (head == NULL || head->next == NULL) {
		return head;
	}
	Node<int>* smallerLLHead = reverse(head->next);
	Node<int>* tail = head->next;
	tail->next = head;
	head->next = NULL;
	return smallerLLHead;
}
int identical(Node<int> *a, Node<int> *b){
	 if (a == NULL && b == NULL)
       return true;
	 if (a != NULL && b != NULL)
       return (a->data == b->data) &&
              identical(a->next, b->next);
    return 0;
}
int main() {
	Node<int>* start1= takeLLInput();
	Node<int>* start2= takeLLInput();
	start1=reverse(start1);
	int ans=identical(start1,start2);
	cout<<ans<<endl;
	delete start1;
	delete start2;
}