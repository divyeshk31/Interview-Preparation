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

node * remleaf(node *root){
    if(!root) {
        cout<<-1<<endl;
        return NULL;
    }
    if(root->left==NULL && root->right==NULL){
        free(root);
        return NULL;
    }
        root->left=remleaf(root->left);
        root->right=remleaf(root->right);
    
    return root;
}

int height(node* root) {
    if (root == NULL)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}
void printGivenLevel(struct node* root, int level, int ltr)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);

    else if (level > 1)
    {
        if(ltr){
        printGivenLevel(root->left, level-1,ltr);
        printGivenLevel(root->right, level-1,ltr);
            }
    else{
        printGivenLevel(root->right, level-1,ltr);
        printGivenLevel(root->left, level-1,ltr);
    }
}
}

void printLevelOrder(node* root)
{
    int h = height(root);
    int i;
    bool ltr=true;
    for (i=1; i<=h; i++)
    {
        printGivenLevel(root,i,ltr);
         cout<<endl;
         ltr=!ltr;
    }
}
int main()
{
    node *root = takeInputLWise();
    printLevelOrder(root);
    //getch();
    return 0;
}