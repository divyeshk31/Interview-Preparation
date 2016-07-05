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

Node<int> *append(Node<int> * root, int k)
{
     Node<int> *prev=NULL;
     Node<int> *curr;
     if(!root||(!root->next)||k<=0){
        return root;
     }
     int m=length(root);
     if(m<=k){
        return root;
     }
        curr = root;
        for (int i = 0; i < k; i++) {
                curr = curr->next;
                if (curr == NULL)
                        return NULL;
        }
        prev = root;
        while (curr->next != NULL) {
                curr = curr->next;
                prev = prev->next;
        }
       curr->next = root;
        root = prev->next;
     prev->next = NULL;
        return root;
}

int main() {
        int k;
        cin>>k;
        Node<int>* start= takeLLInput();
        start=append(start,k);
        print(start);
        delete start;
}