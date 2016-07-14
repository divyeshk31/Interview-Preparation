#include <iostream>
#include <queue>
#include <stdlib.h>
#include <stdio.h>
#include <stack>
#include <map>
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
int getMaxHeight(node* root)
{
    if (root == NULL)
        return 0;

    int leftHeight = getMaxHeight(root->left);
    int rightHeight = getMaxHeight(root->right);

    return max(leftHeight, rightHeight) + 1;
}
void printarray(vector<int> &a, int e){
  for(int i=0;i<=e;i++){
    cout<<a[i]<<" ";
  }
      cout<<endl;
}
void RootToLeafSumPath(int sum, vector<int> &a, int level, node *root ,int &path_exists){
  int temp=0;
  if(!root) return;

 // if(a[level]==root->data){
   // return ;
  //}
  //else{

  a[level]=root->data;

  if(root->left==NULL && root->right==NULL)
  {


        for(int i=level;i>=0;i--)
                {
                    temp+=a[i];

                }
                if(temp==sum){
                        path_exists = 1;
                    printarray(a,level);}

    }

    RootToLeafSumPath(sum,a,level+1,root->left,path_exists);
    RootToLeafSumPath(sum,a,level+1,root->right,path_exists);
}
int main()
{
    int k;
    cin>>k;
    node *root = takeInputLWise();
   vector<int> a (getMaxHeight(root));
   int path_exists = 0;
    RootToLeafSumPath(k,a,0,root,path_exists);

    if(path_exists==0)
    {
        cout<<"-1";
    }
   // getch();
    return 0;
}
