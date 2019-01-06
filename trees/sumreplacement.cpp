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
int replacesum(node*root){
	if(root==NULL)
		return 0;
	if(root->left==NULL && root->right==NULL)
		return root->data;

	int ls=replacesum(root->left);
	int rs=replacesum(root->right);
	int temp=root->data;
	root->data=ls+rs;
	return root->data+temp;
}
int main(){
	node*root=buildtree();
	replacesum(root)
	printpreorder(root);
}