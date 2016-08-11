void rec(node *p){
	if(!p)
		return;
	if(p->left)
		p->left->nextright=p->right;
	if(p->right)
		p->right->nextright=p->nextright?(p->nextright->left)?:NULL;
	rec(p->left);
	rec(p->right);
}
void connect(node *root){
	root->nextright=NULL;
	rec(root);
}