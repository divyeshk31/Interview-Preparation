#include <iostream>
#include <queue>
#include <stdlib.h>
#include <stdio.h>
#include <stack>
#include <map>
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

void vertical_traversal(node *root,int hd,map<int,vector<int> > &hmap)//hd->horizontal distance
{
    if(root==NULL)return;
    hmap[hd].push_back(root->data);
    vertical_traversal(root->left,hd-1,hmap);
    vertical_traversal(root->right,hd+1,hmap);
 
}
 
 
void print_vertical_traversal(node *root)//to carry out vertical order traversal of a binary tree
{
    map<int,vector<int> > hmap;
    vertical_traversal(root,0,hmap);
    map<int,vector<int> >::iterator i;
    vector<int>::iterator v;
    int sum=0;
    for(i=hmap.begin();i!=hmap.end();i++)
    {
      sum=0;
        for( v=i->second.begin();v!=i->second.end();v++)
        {
            sum+=(*v);
        }
        cout<<sum<<" ";
    }
}


int main()
{
    node *root = takeInputLWise();
     print_vertical_traversal(root);
  getch();
  return 0;
}