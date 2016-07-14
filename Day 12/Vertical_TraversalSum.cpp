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

void verticalsum(node *root,int count[],int index,int leftwidth)
{
    if(root==NULL)
        return ;
    verticalsum(root->left,count,index-1,leftwidth);
    count[index+leftwidth]+=root->data;
    verticalsum(root->right,count,index+1,leftwidth);
}

int height(node* root) {
    if (root == NULL)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}
/* Get width of a given level */
int getWidth(node* root, int level)
{

  if(root == NULL)
    return 0;

  if(level == 1)
    return 1;

  else if (level > 1)
    return getWidth(root->left, level-1) +
             getWidth(root->right, level-1);
}
int getMaxWidth(node* root)
{
  int maxWidth = 0;
  int width;
  int h = height(root);
  int i;

  /* Get width of each level and compare
     the width with maximum width so far */
  for(i=1; i<=h; i++)
  {
    width = getWidth(root, i);
    if(width > maxWidth)
      maxWidth = width;
  }

  return maxWidth;
}

int main()
{
    node *root = takeInputLWise();
     int i,width=getMaxWidth(root);
    int leftwidth=getMaxWidth(root->left);
  int count[width+1];
  for(i=0;i<=width;i++)
    count[i]=0;
  verticalsum(root,count,0,leftwidth);
  for(i=0;i<=width;i++)
    printf("%d ",count[i]);
  getch();
  return 0;
}