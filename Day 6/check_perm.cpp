#include <bits/stdc++.h>
#include <tr1/unordered_map>
//#include <conio.h>
using std::tr1::unordered_map;
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
int check(Node<int> *head1,Node<int> *head2)
{
    unordered_map<int,int> map;
    while(head1!=NULL)
    {
        map[head1->data]++;
        head1 = head1->next;
    }
    while(head2!=NULL)
    {
        map[head2->data]--;
        head2 = head2->next;
    }
    unordered_map<int,int>:: iterator it=map.begin();
    for(;it!= map.end();it++)
    {

        if(it->second!=0)
            return 0;
    }
    return 1;
}
int main() {
	Node<int>* start1= takeLLInput();
	Node<int>* start2= takeLLInput();
	int ans=check(start1,start2);
	cout<<ans<<endl;
	//getch();
	delete start1;
	delete start2;
}