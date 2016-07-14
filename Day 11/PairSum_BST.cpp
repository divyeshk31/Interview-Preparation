#include <iostream>
#include <queue>
#include <stdlib.h>
#include <stdio.h>
#include <stack>
#include <conio.h>

using namespace std;
struct node{
    int data;
    node *left;
    node *right;
};
node* getnewnode(int data)
{
    node *temp = new node();
    temp->data = data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
node* takeInputLWise(){
    int rootData;
    cin >> rootData;
    node *root = getnewnode(rootData);
    queue<node *> q;
    q.push(root);
    while(!q.empty())
    {
        node *top=q.front();
        q.pop();
        int child1,child2;
        cin>>child1>>child2;
        if(child1!=-1)
        {
            node *left = getnewnode(child1);
            q.push(left);
            top->left=left;
        }
        if(child2!=-1)
        {
            node *right = getnewnode(child2);
            q.push(right);
            top->right=right;
        }
    }
    return root;
}

bool pairsum(node *root, int x){
    stack<node*> s1,s2;
    node * c1=root, *c2=root;
    while(true){
        while(c1){
            s1.push(c1);
            c1=c1->left;
        }
        while(c2){
            s2.push(c2);
            c2=c2->right;
        }
        if(!s1.empty()&&!s2.empty()){
            c1=s1.top();
            c2=s2.top();
            if(c1->data>=c2->data)
                return false;
            if(c1->data+c2->data==x){
                cout<<c1->data<<" "<<c2->data;
                return true;
            }
            if(c1->data+c2->data>x){
                c1=NULL;
                s2.pop();
                c2=c2->left;
            }
           else if(c1->data+c2->data<x){
                c2=NULL;
                s1.pop();
                c1=c1->right;
            }
        }
        else return false;
    }
}

int main()
{
    int sum;
    cin>>sum;
    node *root = takeInputLWise();
    if(pairsum(root,sum)==false)
        cout<<"-1 -1"<<endl;
    getch();
    return 0;
}