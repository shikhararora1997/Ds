#include<iostream>
using namespace std;

class node{
public:
	int data;
	node*left;
	node*right;

	node(int d){
		data=d;
		left=NULL;
		right=NULL;
	}
};
node*buildtree(){
	 int d;
	 cin>>d;
	 if(d==-1)
	 	return NULL;
	 node *root = new node(d);
	 root->left=buildtree();
	 root->right=buildtree();
	 return root;
}
 
void printpreorder(node*root){
	if(root==NULL)
		return;
	cout<<root->data<<" ";
	printpreorder(root->left);
	printpreorder(root->right);
}

void printinorder(node*root){
	if(root==NULL)
		return;
	printinorder(root->left);
	cout<<root->data<<" ";
	printinorder(root->right);
}
void printpostorder(node*root){
	if(root==NULL)
		return;
	printpostorder(root->left);
	printpostorder(root->right);
	cout<<root->data<<" ";
}
int height(node*root){
	if(root==NULL)
		return 0;
	int ls=height(root->left);
	int rs=height(root->right);
	return max(ls,rs)+1;
}
int main(){
	node*root=buildtree();
	printpreorder(root);
	cout<<endl;
	printinorder(root);
	cout<<endl;
	printpostorder(root);
	cout<<endl;
	cout<<height(root);

	return 0;
}