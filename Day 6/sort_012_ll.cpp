#include <bits/stdc++.h>
#include <conio.h>
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

void sort012(Node<int>* head){
    int c[3]={0};
    Node<int> * cur=head;
    while(cur!=NULL){
        c[cur->data]+=1;
        cur=cur->next;
    }
    int i=0;
    cur=head;
    while(cur!=NULL){
        if(c[i]==0)
            ++i;
    else{
        cur->data=i;
        --c[i];
        cur=cur->next;
    }
  }
}
void sortList(Node<int>*head)
{
   Node<int>*curr=head;
    int i=0,j=0,k=0;
 
    while(curr)
    {
        if(curr->data==0) i++;
        else if(curr->data==1) j++;
        else k++;
        curr=curr->next;
    }
    curr=head;
    while(i)
    {
        curr->data=0;
        curr=curr->next;
        i--;
    }
    while(j)
    {
        curr->data=1;
        curr=curr->next;
        j--;
    }
    while(k)
    {
        curr->data=2;
        curr=curr->next;
        k--;
    }
}
int main() {
        Node<int>* start= takeLLInput();
        sort012(start);
        print(start);
        delete start;
        getch();
}