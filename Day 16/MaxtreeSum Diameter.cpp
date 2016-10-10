#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

struct node{
    int data;
    node *left, *right;
    node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

node* createTree(int data){
    return new node(data);
}

int maxLeafSum(node* root, int &res){
    if (root == NULL) return 0;
    if(!root->left&&!root->right)
        return root->data;
    int ls = maxLeafSum(root->left, res);
    int rs = maxLeafSum(root->right, res);
    res=max(res,ls+rs+root->data);
    return max(ls, rs) + root->data;
}

int maxDiameterSum(int nodes, int tree[511]){
    node* root, *newt;
    vector<node*> node_list;
    int i=0;
    root=createTree(tree[0]);
    node_list.push_back(root);
    while(!node_list.empty()){
        newt=node_list.front();
        node_list.erase(node_list.begin());
        if(2*i+1>=nodes)
            break;
        newt->left=createTree(tree[2*i+1]);
        node_list.push_back(newt->left);
        if(2*i+2>=nodes)
            break;
        newt->right=createTree(tree[2*i+2]);
        node_list.push_back(newt->right);
        i+=1;
    }
    int res=INT_MIN;
    maxLeafSum(root, res);
    return res;
}

int main() {
    int T, N, A[511];
    int i;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&N);
        for(i=0;i<N;i++) {
            scanf("%d",&A[i]);
        }
        printf("%d\n",maxDiameterSum(N,A));
    }
    return 0;
}
