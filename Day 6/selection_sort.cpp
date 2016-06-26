#include <iostream>
#include <string>
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
void selection(Node<int> *A){
	Node<int> *h=A;
	Node<int> *i,*j,*min;
	for(i=h;i!=NULL&&i->next!=NULL;i=i->next){
		min=i;
		for(j=i->next;j!=NULL;j=j->next){
			if(j->data<min->data)
				min=j;
		}
		if(min!=i){
			int t=min->data;
			min->data=i->data;
			i->data=t;
		}
	}
	A=h;
}
int main() {
	Node<int>* head = takeLLInput();
	selection(head);
	print(head);
	delete head;
//	getch();
//	return 0;
}
