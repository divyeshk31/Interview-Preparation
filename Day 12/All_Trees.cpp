#include <iostream>
#include<cstdio>
#include <cstdlib>
#include <algorithm>
#include <list>
#include <stack>
#include <map>
#include <vector>
#include <queue>
using namespace std;

//int sum;

struct node
{
    int data;
    struct node *left;
    struct node *right;
    struct node *next;
};

struct node* newnode(int data)
{
    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
};

void preorder(struct node*root)
{
    if(root==NULL)return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);

}

void inorder(struct node * root)
{
    if(root==NULL)return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}


void iterative_inorder(struct node *root)
{
    struct node *current=root;
    bool flag=false;
    stack<struct node *> s;
    while(flag!=true)
    {
        while(current!=NULL)
        {
            s.push(current);
            current=current->left;
        }
        if(s.empty()){flag=true;}
        else
        {current=s.top();
        s.pop();
        printf("%d ",current->data);
        current=current->right;
        }
    }
}
void postorder(struct node *root)
{
    if(root==NULL)return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

struct node * insert_node(struct node*root,int key)
{
    if(root==NULL)
        return newnode(key);
    else if(key>root->data)
        root->right=insert_node(root->right,key);
    else
        root->left=insert_node(root->left,key);
        return root;
};

struct node* Minvaluenode(struct node *node)
{
    //if(root==NULL)return;
    struct node *temp=node;
    while(temp->left!=NULL)
    {
        temp=temp->left;
    }
    return temp;
};
struct node *delete_node(struct node* root,int key)
{
    if(root==NULL)return root;
    if(key>root->data)
        root->right=delete_node(root->right,key);
    else if(key<root->data)
        root->left=delete_node(root->left,key);
    else
    {
        if(root->left==NULL)
        {
            struct node* temp=root->right;
            root->data=temp->data;
            free(temp);
        }
        else if(root->right==NULL)
        {
            struct node* temp=root->left;
            root->data=temp->data;
            free(temp);
        }

        {struct node *temp=Minvaluenode(root->right);
        root->data=temp->data;
        root->right=delete_node(root->right,temp->data);}
    }
    return root;
}

int maxdepth(struct node *root)
{
    if(root==NULL)
        return 0;
    else
        return max(maxdepth(root->right),maxdepth(root->left))+1;
}

void printarr(int path[],int path_var)
{
    for(int i=0;i<path_var;i++)printf("%d ",path[i]);
    printf("\n");
}
void Print_path_recursion(struct node *root,int path[],int path_var)
{
    if(root==NULL)return;
    else
    path[path_var]=root->data;
    path_var++;
    if(root->left==NULL && root->right==NULL)
        printarr(path,path_var);
    else
    {
        Print_path_recursion(root->right,path,path_var);
        Print_path_recursion(root->left,path,path_var);
    }

}


int find_sum(struct node *root,int sum,int path[],int path_var)//to check if a particular sum exists in any path
{
    int result=0;
    if(root==NULL)return 0;
    else
    path[path_var]=root->data;
    path_var++;
    if(root->left==NULL && root->right==NULL)
    {
        for(int i=0;i<path_var;i++)
            result+=path[i];
        if(result==sum)return 1;
    }
    else
    {
        find_sum(root->right,sum,path,path_var);
        find_sum(root->left,sum,path,path_var);
    }

    return 0;

}

int findsum1(struct node *root,int sum)//check whether a particular sum exists in any path in the tree
{
    if(root==NULL)
    return(sum==0);
    else
    {sum=sum-root->data;
    return (findsum1(root->right,sum) || findsum1(root->left,sum));
    }

}

void level_order_traversal(struct node *root)//also known as the BFS traversal in a tree
{
    struct node *temp;
    temp=root;
    list<struct node *>q;
    while(temp!=NULL)
    {
        cout<<temp->data<<endl;
        if(temp->left!=NULL)
            q.push_back(temp->left);
        if(temp->right!=NULL)
            q.push_back(temp->right);
        if(!q.empty())
        {
            temp=q.front();
            q.pop_front();
        }
        else temp=NULL;

    }
}

int check_sum_property(struct node *root)//to check if the tree satisfies the property that for any node,it's data value should be
//equal to the sum of the data values of it's right and left child
{
    if(root==NULL || (root->left==NULL && root->right==NULL))return 1;
    int left_data=0,right_data=0;
    if(root->left!=NULL)left_data=root->left->data;
    if(root->right!=NULL)right_data=root->right->data;

    if((root->data==left_data+right_data) &&(check_sum_property(root->left))&& (check_sum_property(root->right)))return 1;
    else return 0;
}

void sum_of_right_subtree(struct node *root,int * sum)
{
    if(root==NULL)return ;
    sum_of_right_subtree(root->right,sum);
    *sum=*sum+root->data;
    root->data=*sum;
    sum_of_right_subtree(root->left,sum);
}

int max(int a,int b,int c)
{
    return (a>b)?((a>c)?a:c):((b>c)?b:c);
}
int max_weight(struct node *root)//find the maximum sum subtree in a tree->NOT WORKING
{
    if(root==NULL)return 0;
    else
    {int left=max_weight(root->left);
    int right=max_weight(root->right);
    int a=max_weight(root->right)+max_weight(root->left)+root->data;
    return max(left,right,a);
    }
}


void vertical_traversal(struct node *root,int hd,map<int,vector<int> > &hmap)//hd->horizontal distance
{
    if(root==NULL)return;
    hmap[hd].push_back(root->data);
    vertical_traversal(root->left,hd-1,hmap);
    vertical_traversal(root->right,hd+1,hmap);

}


void print_vertical_traversal(struct node *root)//to carry out vertical order traversal of a binary tree
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
        cout<<sum<<endl;;
    }
}

int print(int arr[],int i)
{
    int temp=0;
    for(int j=0;j<i;j++)
       {temp+=arr[j];
       //printf("%d ",temp);
        printf("%d ",arr[j]);

       }
    printf("\n");
    return temp;
}


void print_max_path(struct node *root,int path[],int i,int *max_sum)//find the maximum sum in a tree from root to leaf
{
    if(root==NULL)return;
    path[i++]=root->data;
    if(root->left==NULL && root->right==NULL)
    {
        int temp=print(path,i);
        if(temp>*max_sum)*max_sum=temp;
    }
    else
    {

        print_max_path(root->left,path,i,max_sum);
        print_max_path(root->right,path,i,max_sum);
    }

}


void store_sum(struct node *root)//replace every node in a binary tree with the sum of all the nodes greater than it
{
    int sum=0;
    if(root==NULL)return;
    struct node *temp=root;
    stack<struct node *>s;
    while(temp)
    {
        s.push(temp);
        temp=temp->right;
    }
    while(!s.empty())
    {
        temp=s.top();
        s.pop();
        sum=sum+temp->data;
        temp->data=sum;
        if(temp->left)
        store_sum(temp->left);
    }

}

void print_left_view(struct node *root,int level,int *max_level)//print the leftmost nodes of each level->left view
{
    if(root==NULL)return;
    if(level>*max_level)
    {
        printf("%d ",root->data);
        *max_level=level;
    }
    print_left_view(root->left,level+1,max_level);
    print_left_view(root->right,level+1,max_level);
}

void spiral_order_traversal(struct node *root)
{
    bool itr=false;
    struct node *temp;
    stack<struct node *> s1,s2;
    s1.push(root);
    while(!s1.empty())
    {
        temp=s1.top();
        printf("%d ",temp->data);
        s1.pop();
        if(itr==true)
        {
            if(temp->left)s2.push(temp->left);
            if(temp->right)s2.push(temp->right);
        }
        else
        {
            if(temp->right)s2.push(temp->right);
            if(temp->left)s2.push(temp->left);
        }

        if(s1.empty())
        {
        itr=!itr;
        swap(s1,s2);
        }
    }

}

void convert_binary_tree_to_ll(struct node *root,struct node **head)
{
    if(root==NULL)return;
    struct node* prev=NULL;
    convert_binary_tree_to_ll(root->left,head);
    root->left=prev;
    if(prev)
        prev->right=root;
    else
        *head=root;
    convert_binary_tree_to_ll(root->right,head);


}

int find_closest_element(struct node *root,int k)
{
    if(root->left==NULL && root->right==NULL)return root->data;
    if(k<=root->data)
    {
        int left=find_closest_element(root->left,k);
        return ((root->data-k<=k-left)?root->data:left);
    }
    else
    {
        int right=find_closest_element(root->right,k);
        return ((k-root->data<=right-k)?root->data:right);
    }
}

void createlist(struct node *root,struct node **head,struct node **prev)//link the nodes of a binary tree to form a ll
{

    if(root==NULL)return;
    createlist(root->left,head,prev);
    if(root->left==NULL && root->right==NULL)
        {
            if(*prev==NULL)
            {*head=root;
            *prev=root;}
            else
            {
                (*prev)->right=root;
                *prev=root;
            }
        }


    createlist(root->right,head,prev);



};

struct node * mirror_tree(struct node * root)
{
    if(!root)return NULL;
    struct node *temp= newnode(root->data);
    if(root->left)temp->right=mirror_tree(root->left);
    if(root->right)temp->left=mirror_tree(root->right);
    return temp;
};

void populate_next_pointer(struct node *root,struct node* &prev)
{
    if(root==NULL)return;
    //if(root->left==NULL && root->right==NULL)return root;
    populate_next_pointer(root->left,prev);
    if(prev){prev->next=root;prev=root;}
    else {prev=root;}
    populate_next_pointer(root->right,prev);
    //return root;
}

bool check_leaves_at_same_level(struct node *root,int k,int &m)
{
    if(root==NULL)return true;
    if(root->left==NULL && root->right==NULL && m==-1)m=k;
    if(root->left==NULL && root->right==NULL && m!=-1 && m!=k)return false ;
    if(root->left==NULL && root->right==NULL && m==k)return true;
    return (check_leaves_at_same_level(root->left,k+1,m) && check_leaves_at_same_level(root->right,k+1,m));

}

void postorder_iterative(struct node *root)
{
    if(!root)return;
    stack<pair <struct node *,bool> > s;
    pair<struct node *,bool> temp(root,0),temp1;
    s.push(temp);
    while(!s.empty())
    {
        temp=s.top();//here a copy of s.top() is being created,temp is another copy of s.top
        if(temp.second==1)
        {
            cout<<temp.first->data<<" ";
            s.pop();
             continue;
        }
        if(temp.second==false)
        {
            s.top().second=1;
        }

        if(temp.first->right)
        {
            temp1.first=temp.first->right;
            temp1.second=0;
            s.push(temp1);
        }
        if(temp.first->left)
        {
            temp1.first=temp.first->left;
            temp1.second=0;
            s.push(temp1);
        }
    }
}

void print_right_view(struct node *root)
{
    if(root==NULL)return;
    queue<struct node *> q;
    struct node *temp=NULL;
    q.push(root);
    q.push(temp);
    while(!(q.size()==1))
    {
        struct node *T=q.front();
        q.pop();
        if(T==NULL){q.push(T);continue;}
        if(q.front()==NULL)cout<<T->data<<" ";
        if(T->left)q.push(T->left);
        if(T->right)q.push(T->right);
    }
}

struct node* binary_tree_to_dll(struct node *root,struct node *&head,struct node *&tail)//convert binary tree to dll such that traversal of list produces inorder traversal of the tree
{
    if(root==NULL)return NULL;
    binary_tree_to_dll(root->left,head,tail);
    if(!tail){head=root;tail=root;}
    else
        tail->right=root;
        root->left=tail;
    tail=root;
    binary_tree_to_dll(root->right,head,tail);
    return root;

};

void print_k_nodes_down(struct node* root,int k)
{
    if(root==NULL || k<0)return;
    if(k==0){cout<<root->data<<" ";return;}
    else{
        print_k_nodes_down(root->left,k-1);
        print_k_nodes_down(root->right,k-1);
    }
}

/*bool is_present(struct node* root,struct node *&temp)
{
    if(root==NULL)return false;
    if(root==temp)return true;
    return (is_present(root->left,temp) || is_present(root->right,temp));
}

int find_distance(struct node *root,struct node *temp,int k)
{
    if(root==NULL)return -1;
    if(root==temp)return k;
    else
    {
        find_distance(root->left,temp,k+1);
        find_distance(root->right,temp,k+1);
    }
}
 bool print_k_nodes(struct node* root,int k,struct node *temp,int level)
 {
     if(root==NULL)return;
     int D=find_distance(root,temp,0);
     bool left=is_present(root->left);
     if(left)print_k_nodes_down(root->right,k-(D-level));
     else
        print_k_nodes_down(root->left,k-(D-level));
     print_k_nodes(root->left,k,temp,level+1);
     print_k_nodes(root->right,k,temp,level+1);

 }
 */

 int print_k_dist_nodes(struct node *root,struct node* target,int k)
 {
     if(root==NULL)return -1;
     if(root==target)
     {
         print_k_nodes_down(root,k);
         return 0;
     }
     int dl=print_k_dist_nodes(root->left,target,k);//dl indicates the distance of the target node from root->left,which means if
     //dl is not equal to -1 and we want to find the k distance nodes on the right side of root we will have to look at a distance
     //of k-dl-2 as k-dl is remaining distance from root->left and when we consider the root and root->right as we start looking
     //below root->right so these two have to be taken into account making the total distance k-dl-2;
     if(dl != -1)
     {
         if(dl+1==k)cout<<root->data<<endl;
         else print_k_nodes_down(root->right,k-dl-2);
         return dl+1;//dl+1 will be the distance of the target node from the root that called the function for root->left
     }
     int dr=print_k_dist_nodes(root->right,target,k);
     if(dr != -1)
     {
         if(dr+1==k)cout<<root->data<<endl;
         else print_k_nodes_down(root->left,k-dl-2);
         return dr+1;
     }
     return -1;//if both are not present
 }

 vector<struct node *>create_bst(int start,int end)
 {
     vector<struct node *> list;
     if(start>end)
     {
         list.push_back(NULL);
         return list;
     }

     for(int i=start;i<=end;i++)
     {
        vector<struct node*> left_subtree=create_bst(start,i-1);//create a vector of all the possible left subtrees
        vector<struct node *> right_subtree=create_bst(i+1,end);//create a vector of all the possible right subtrees
        //join all the left subtrees and right subtrees in all possible combinations to generate all possible trees
        for(int j=0;j<left_subtree.size();j++)
        {
            struct node *left=left_subtree[j];
            for(int k=0;k<right_subtree.size();k++)
            {
                struct node *right=right_subtree[k];
                struct node *root=newnode(i);
                root->left=left;
                root->right=right;
                list.push_back(root);
            }
        }

     }
     return list;
 }
 vector<struct node*>create_BST(int n)//create all possible bsts from n nodes
 {
     return create_bst(1,n);
 }

int main()
{
    //struct node *root=NULL;
    //int path[100],path_var=0;
    /*root->left=newnode(2);
    root->right=newnode(3);
    root->left->left=newnode(4);
    root->left->right=newnode(5);*/
    /*root=insert_node(root,50);
    insert_node(root,30);
    insert_node(root,20);
    insert_node(root,40);
    insert_node(root,70);
    insert_node(root,60);
    insert_node(root,80);*/
    struct node *root  = newnode(1);
    root->left         = newnode(2);
    root->right        = newnode(3);
    root->left->left   = newnode(4);
    root->left->right  = newnode(5);
    root->right->right = newnode(7);
    root->right->left  = newnode(6);
    struct node *temp=root->left;
    //preorder(root);
    //printf("\n");
    //inorder(root);
    //printf("\n");
    //root=delete_node(root,20);
    //inorder(root);
    //printf("%d\n",maxdepth(root));
    //Print_path_recursion(root,path,path_var);
    //path_var=0;
    //printf("%d ",findsum1(root,120));
    //postorder(root);
    //printf("\n");
    //level_order_traversal(root);
    //printf("%d ",check_sum_property(root));
    //int sum=0;
    //sum_of_right_subtree(root,&sum);
    //inorder(root);
    //cout<<endl;
    //iterative_inorder(root);
    //printf("%d\n",max_weight(root));
    //print_vertical_traversal(root);
    //int path[100];
    //int y=0;
    //max_sum_path(root,path,0);
    //printf("%d\n",y);
    //printf("\n");
    //print_max_path(root,path,0,&y);
    //printf("%d\n",y);
    //store_sum(root);
    //inorder(root);
    //int y=0;
    //print_left_view(root,1,&y);
    //spiral_order_traversal(root);
    //printf("%d",find_closest_element(root,1));
    /*struct node *head=NULL;
    struct node *prev=NULL;
    createlist(root,&head,&prev);
    while(head){cout<<head->data<<" ";head=head->right;}
        */
        /*struct node*result=mirror_tree(root);
    inorder(result);
    */
    /*struct node*prev=NULL;
    populate_next_pointer(root,prev);
    while(root->left!=NULL)
    {
        root=root->left;
    }
    while(root)
    {
        cout<<root->data<<" ";
        root=root->next;
    }
    */
    /*int k=-1;
    cout<<check_leaves_at_same_level(root,0,k);
    */
    //postorder_iterative(root);
    //print_right_view(root);
    /*struct node*head=NULL,*tail=NULL;
    binary_tree_to_dll(root,head,tail);
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->right;
    }
    */
    print_k_dist_nodes(root,temp,3);
        return 0;
}
