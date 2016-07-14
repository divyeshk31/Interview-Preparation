#include <iostream>
#include <queue>
#include <stdlib.h>
#include <stdio.h>
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
int search(int in[], int inStart, int inEnd, int val){
    for(int i=inStart;i<=inEnd;i++){
        if(in[i]==val)
            return i;
    }
}

node * build(int in[], int pre[], int inStart, int inEnd){
    static int preOrder=0;
    if(inStart>inEnd) return NULL;
    node *newNode = getnewnode(pre[preOrder++]);
    if(inStart==inEnd)
        return newNode;
    int inOrder=search(in,inStart,inEnd,newNode->data);
    newNode->left=build(in,pre,inStart,inOrder-1);
    newNode->right=build(in,pre,inOrder+1,inEnd);
    return newNode;
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
   {
     printGivenLevel(root, i);
     cout<<endl;
    }
}

int main()
{
    int n;
    cin>>n;
    int pre[n],in[n];
    for (int i = 0; i < n; i++)
    {
        cin>>pre[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>in[i];
    }
    node* root=build(in, pre, 0 ,n-1);
    printLevelOrder(root);
    //getch();
    return 0;
}