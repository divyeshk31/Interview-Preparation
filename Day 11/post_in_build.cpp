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

node * build(int in[], int post[], int inStart, int inEnd,int postend){
    if(inStart>inEnd) return NULL;
    node *newNode = getnewnode(post[postend]);
    int mid;
            for (int i=inStart;i<=inEnd;i++){
                if (in[i]==newNode->data)
                    {
                        mid = i;
                        break;
                    }
            }
    newNode->right=build(in,post,mid+1,inEnd,postend-1);
    newNode->left=build(in,post,inStart,mid-1,postend-1-inEnd+mid);
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
    int post[n],in[n];
    for (int i = 0; i < n; i++)
    {
        cin>>post[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>in[i];
    }
    node* root=build(in, post, 0 ,n-1,n-1);
    printLevelOrder(root);
   //getch();
    return 0;
}