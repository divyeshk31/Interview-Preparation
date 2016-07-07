#include <iostream>
#include <queue>
#include <stdlib.h>
#include <stdio.h>
//#include <conio.h>
#include <stack>

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

void preorder_iterative(node *root){
    if(!root)
        return;
    stack<node*> st;
    st.push(root);
    while(st.empty()==false){
        node *t=st.top();
        cout<<t->data<<" ";
        st.pop();
        if(t->right)
            st.push(t->right);
        if(t->left)
            st.push(t->left);
    }
}
void preorder_recursive(node *root){
    if(!root)
        return;
    cout<<root->data<<" ";
    preorder_recursive(root->left);
    preorder_recursive(root->right);
}

int main()
{
    node *root = takeInputLWise();
    //preorder_recursive(root);
    preorder_iterative(root);
   // getch();
    return 0;
}