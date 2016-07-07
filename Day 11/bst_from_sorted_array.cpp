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
node * MakeBST(int a[], int l, int r){
    if(l>r)
        return NULL;
        int mid=(l+r)/2;
        node* root=getnewnode(a[mid]);
        root->left=MakeBST(a,l,mid-1);
        root->right=MakeBST(a,mid+1,r);
    return root;
}
int height(node* root) {
    if (root == NULL)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

void printGivenLevel( node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
       cout<<root->data<<" ";

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
    int n;
    cin>>n;
    int a[n+2];
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
    }
    node *root=MakeBST(a,0,n-1);
    printLevelOrder(root);
    //getch();
    return 0;
}