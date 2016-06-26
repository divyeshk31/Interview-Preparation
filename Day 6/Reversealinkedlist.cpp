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
	if (head == NULL || head->next == NULL) {
		return head;
	}
	Node<int>* smallerLLHead = reverse(head->next);
	Node<int>* tail = head->next;
	tail->next = head;
	head->next = NULL;
	return smallerLLHead;
}

void merge(Node<int>* head) {
	int llLength = length(head);
	Node<int>* midNode = getNthNode(head, (llLength + 1)/2 - 1);
	Node<int>* second = midNode->next;
	midNode->next = NULL;
	Node<int>* first = head;
	while(first != NULL && second != NULL) {
		Node<int>* temp = second->next;
		second->next = first->next;
		first->next = second;
		first = second->next;
		second = temp;
	}
}

int main() {
	Node<int>* head = takeLLInput();
	head = reverse(head);
	print(head);
	delete head;
}
