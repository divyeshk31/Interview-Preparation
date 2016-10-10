//K reverse Linked List
node *rev(node *head, int k){
	if(!head) return NULL;
	int count=0;
	node* next=NULL;
	node*cur=head;
	node* temp=NULL;
	while(cur!=NULL && count<k){
		next=cur->next;
		cur->next=temp;
		temp=cur;
		cur=next;
		c++;
	}
	if(next!=NULL)
		head>next=rev(next,k);
	return temp;
}
//ModifyBST 
node *ModifyBST(node* root, int *sum){
	if(!root)
		return NULL;
	ModifyBST(root->right,sum);
	*sum+=root->data;
	root->data=*sum;
	ModifyBST(root->left,sum);
	return root;
}
//