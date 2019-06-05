#include<iostream>

class node{
public:
	int data;
	node *left,*right;
	node(int data){
		this->data=data;
		left=NULL;
		right=NULL;
	}
	~node(){
		if(!left)
			delete(left);
		if(!right)
			delete(right);
	}
};

//Code to display inorder successor of BST... 'Always in sorted order'
void dispbst(node *root){
	if(root!=NULL){
		dispbst(root->left);
		std::cout<<root->data<<" ";
		dispbst(root->right);
	}
}

//Insertion into BST
node *insertbst(node *root,int val){
	if(root==NULL)
		return (new node(val));
	if(root->data>val)
		root->left=insertbst(root->left,val);
	if(root->data<val)
		root->right=insertbst(root->right,val);
	return root;
}

//Searches and returns a node based on the key value
node *search(node *root,int key){
	if(root==NULL||root->data==key)
		return root;
	if(root->data<key)
		return search(root->right,key);
	return search(root->left,key);
}

//Utility function for BST deletion
node *inordersuccessor(node *root){
	node *temp=root->left==NULL?root:inordersuccessor(root->left);
	return temp;
}
//Delete a node from BST
node *deletenode(node *root,int val){
	if(root==NULL){
		std::cout<<"Element to be deleted not found";
		return root;
	}
	if(root->data > val)
		root->left=deletenode(root->left,val);
	if(root->data < val)
		root->right=deletenode(root->right,val);
	else{
		if(root->left==NULL){
			node * temp= root->right;
			delete(root);
			return temp;
		}
		else if(root->right==NULL){
			node * temp=root->left;
			delete(root);
			return temp;
		}
		else{
			node *temp= inordersuccessor(root->right);
			root->data = temp->data;
			root->right= deletenode(root->right,root->data);
		}
	}
	return root;
}

int main(){	
	node *root=NULL;
	root=insertbst(root,1);
	insertbst(root,16);
	insertbst(root,21);
	insertbst(root,10);
	insertbst(root,40);
	insertbst(root,25);
	insertbst(root,15);
	dispbst(root);
	deletenode(root,40);
	std::cout<<"\n";
	dispbst(root);
	deletenode(root,16);
	std::cout<<"\n";
	dispbst(root);
	std::cout<<"\n";
	delete(root);
}
