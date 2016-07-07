#include <iostream>
#include <stack>
#include <stdio.h>
using namespace std;

struct node
{
    int data;
    struct node *left,*right;
};

typedef struct node Node;

Node* newNode(int data)
{
    Node* newnode=new Node;
    newnode->data=data;
    newnode->left=newnode->right=NULL;
    return newnode;
}

Node* insert(Node* root,int x)
{
    if(!root) return newNode(x);

    Node *curr=root,*par;

    while(curr)
    {
        par=curr;
        if(curr->data>x)
            curr=curr->left;
        else curr=curr->right;
    }

    if(par->data>x) par->left=newNode(x);
    else par->right=newNode(x);

    return root;
}

void printInorder(Node* root)
{
    if(root)
    {
        printInorder(root->left);
        cout<<root->data<<" ";
        printInorder(root->right);
    }
}

bool isPairPresent(Node* root,int x)
{
    stack<Node*> s1,s2;
    Node *curr1=root,*curr2=root;

    while(true)
    {
        while(curr1)
        {
            s1.push(curr1);
            curr1=curr1->left;
        }
        while(curr2)
        {
            s2.push(curr2);
            curr2=curr2->right;
        }
        if(!s1.empty()&&!s2.empty())
        {
            curr1=s1.top();
            curr2=s2.top();

            if(curr1->data>=curr2->data) return false;

            if(curr1->data+curr2->data==x)
            {
                cout<<"Pair Found: "<<curr1->data<<","<<curr2->data<<endl;
                return true;
            }

            if(curr1->data+curr2->data>x)
            {
                curr1=NULL;
                s2.pop();
                curr2=curr2->left;
            }
            else if(curr1->data+curr2->data<x)
            {
                curr2=NULL;
                s1.pop();
                curr1=curr1->right;
            }
        }
        else return false;
    }
}

int main()
{
    /*
                   15
                /     \
              10      20
             / \     /  \
            8  12   16  25    */
    struct node *root =  newNode(15);
    root->left = newNode(10);
    root->right = newNode(20);
    root->left->left = newNode(8);
    root->left->right = newNode(12);
    root->right->left = newNode(16);
    root->right->right = newNode(25);

    int target = 33;
    if (isPairPresent(root, target) == false)
        printf("\n No such values are found\n");
    return 0;
}
