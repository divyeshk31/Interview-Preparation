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

Node<int>* getNthNode(Node<int>* head, int n) {
	for (int i = 0; i < n;  i++) {
		head = head->next;
	}
	return head;
}

Node<int>* evenafterodd(Node<int>* head)
{
	if(head==NULL)
            return NULL;
	Node<int>*odd=NULL;
      Node<int>*even=NULL;
       Node<int>*oend=NULL;
   Node<int>*eend=NULL;
      Node<int>*itr=head;
        while(itr!=NULL){
            if((itr->data)%2==0){
                if(even==NULL){
                even=eend=itr;
            }
            else{
                eend->next=itr;
                eend=itr;
            }
        }
        else{
            if(odd==NULL){
                odd=oend=itr;
            }
            else{
                oend->next=itr;
                oend=itr;
            }
        
       
        }
        itr=itr->next;
        
    }
    if(!oend){
    	eend->next=NULL;
    	return even;
    }
    if(even)oend->next=even;
    else oend->next=NULL;
    if(eend)eend->next=NULL;
    return odd;
    }
int main() {
	Node<int>* start = takeLLInput();
	start = evenafterodd(start);
	print(start);
	delete start;
	//getch();
}
