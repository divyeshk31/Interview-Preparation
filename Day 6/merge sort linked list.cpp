#include <iostream>
#include <string>
#include <conio.h>
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
Node<int>* sortedM(Node<int>* a,Node<int>* b){
  Node<int>* res=NULL;
    if(!a) return b;
    else if(!b) return a;
    if(a->val<=b->val){
        res=a;
        res->next=sortedM(a->next,b);
    } else{
        res=b;
        res->next=sortedM(a,b->next);
    }
    return res;
}
void split(Node<int>* head, Node<int>** aRef, Node<int>** bRef){
        Node<int>* slow;
        Node<int>* fast;
        if (head==NULL || head->next==NULL){
            *aRef = head;
            *bRef = NULL;
        }else{
            slow = head;
            fast = head;
            while (fast!=NULL && fast->next!=NULL){
                fast = fast->next->next;
                if (fast==NULL){break;} 
                slow = slow->next;
            }
            *aRef = head;
            *bRef = slow->next;
            slow->next=NULL;
        }
    }
void mergeS(Node<int>** A){
Node<int>* head=*A;
    Node<int> *a,*b;
    if(head==NULL||head->next==NULL){
        return;
    }
    split(head,&a,&b);
    mergeS(&a); mergeS(&b);
    *A=sortedM(a,b);
}
int main() {
	Node<int>* head = takeLLInput();
	mergeS(&head);
	print(head);
	delete head;
	getch();
	return 0;
}
