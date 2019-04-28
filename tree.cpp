#include<iostream>
#include<queue>
class person{
public:
	int num;
	person *left,*right;
	person(int num){
		this->num=num;
		left=NULL;
		right=NULL;
	}
};
void inorder(person *root){
	if(root==NULL)return;
	inorder(root->left);
	std::cout<<root->num;
	inorder(root->right);
}
void preorder(person *root){
	if(root==NULL)return;
	std::cout<<root->num;	
	preorder(root->left);
	preorder(root->right);
}
void postorder(person *root){
	if(root==NULL)return;
	postorder(root->left);
	postorder(root->right);
	std::cout<<root->num;
}
void levelorder(person *root){
	if(root==NULL)return;
	std::queue<person *> temp;
	temp.push(root);
	while(!temp.empty()){
		std::cout<<temp.front()->num;
		if(temp.front()->left!=NULL)
			temp.push(temp.front()->left);
		if(temp.front()->right!=NULL)
			temp.push(temp.front()->right);
		temp.pop();
	}
}
int main(){
	person *root=new person(1);
	root->left= new person(2);
	root->right= new person(3);
	root->left->left= new person(4);
	root->left->right= new person(5);
	root->right->left= new person(6);
	root->right->right= new person(7);

	//GUI
	int choice=-1;
	while(choice!=0){
		system("cls");
		std::cout<<"\n\n\tMain Menu\n";
		std::cout<<"\t --   -- \n";
		std::cout<<"1.Inorder\n";
		std::cout<<"2.Postorder\n";
		std::cout<<"3.Preorder\n";
		std::cout<<"4.Level Order\n";
		std::cout<<"0.Exit\n";
		std::cin>>choice;
		std::cout<<"\n";
		switch(choice){
			case 1:	inorder(root);
					break;
			case 2:postorder(root);
					break;
			case 3:preorder(root);
					break;
			case 4:levelorder(root);
					break;
			default:choice=-1;
					break;
			case 0:exit(0);
		}	
		std::cout<<"\n";
		system("pause");
	}
}