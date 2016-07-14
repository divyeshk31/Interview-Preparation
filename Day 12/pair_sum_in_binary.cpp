#include <iostream>
#include <queue>
#include <stdlib.h>
#include <stack>
#include <vector>
//#include <conio.h>
#include <map>

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


void inorder(node *root, map<int ,int> &mymap)
{
    if(root==NULL)
        return ;
    inorder(root->left,mymap);
    mymap[root->data]++;
    inorder(root->right,mymap);
}

void check_pair(node *root, map<int ,int> &mymap,int k,int &flag)
{
    if(root==NULL || flag==1)
        return ;
    check_pair(root->left,mymap,k,flag);
    int val = k - root->data;
    if(mymap.count(val)==1 && val!=root->data)
    {
        flag = 1;
        return;
    }
    check_pair(root->right,mymap,k,flag);
}

void find_pair(node *root,int k)
{
    map<int,int> mymap;
    inorder(root, mymap);
    int flag=0;
    check_pair(root,mymap,k,flag);
    if(flag==0)
    {
        cout<<"0";
    }
    else
    {
        cout<<"1";
    }
}

int main()
{
    int k;
    cin>>k;
    node *root = takeInputLWise();
    find_pair(root,k);
    //getch();
    return 0;
}


