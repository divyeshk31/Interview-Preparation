#include <iostream>
#include <queue>
#include <stack>
#include <stdlib.h>
#include <stdio.h>
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

void recinorder(node *root){
    if(!root) return;
    recinorder(root->left);
    cout<<root->data<<" ";
    recinorder(root->right);
}

void iteinorder(node * root){
    stack<node*> s;
    s.push(root);
    while(!s.empty()){
        node *t = s.top();
        if(t->left){
            s.push(t->left);
            t->left=NULL;
    }
    else{
        cout<<t->data<<" ";
        s.pop();
       if(t->right)
       s.push(t->right);
        }
    }  
}
int height(node* root) {
    if (root == NULL)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

void printGivenLevel(struct node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);

    else if (level > 1)
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}

void printLevelOrder(node* root)
{
    int h = height(root);
    int i;
    for (i=1; i<=h; i++)
        {printGivenLevel(root, i);
    cout<<endl;
}
}

int main()
{
    node *root = takeInputLWise();
    //recinorder(root);
    iteinorder(root);
    //printLevelOrder(root);
    getch();
    return 0;
}