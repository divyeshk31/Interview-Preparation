#include <iostream>
#include <queue>
#include <stdlib.h>
//#include <conio.h>

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
int max(int a, int b)
{
  return (a >= b)? a: b;
} 
int maxsumpossible(node *root, bool caninclude){
    if(!root) return 0;
    if(!caninclude){
        return maxsumpossible(root->left,true)+maxsumpossible(root->right,true);
    }
    else
    {
        int option1=root->data+maxsumpossible(root->left,false)+maxsumpossible(root->right,false);
        int option2=maxsumpossible(root->left,true)+maxsumpossible(root->right,true);
        return max(option2,option1);
    }
}


void print(node *root)
{
    if(root==NULL)
        return;
    queue<node*>q;
    q.push(root);
    while(!q.empty())
    {
        node *temp = q.front();
        cout<<temp->data<<" ";
        q.pop();
        if(temp->left!=NULL)
        {
            q.push(temp->left);
        }
        if(temp->right!=NULL)
        {
            q.push(temp->right);
        }
    }
}
int main()
{
    node *root = takeInputLWise();
    bool caninclude=true;
    int ans =maxsumpossible(root,caninclude);
    cout<<ans<<endl;
    //print(root);
    //getch();
    return 0;
}