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
int height(node*root){
	if(root==NULL)
		return 0;
	int ls=height(root->left);
	int rs=height(root->right);
	return max(ls,rs)+1;
}
int diameter(node*root){
	if(root==NULL)
		return 0;
	int op1=height(root->left)+height(root->right);
	int op2=diameter(root->left);
	int op3=diameter(root->right);
	int maxi=max(op1,op2);
	maxi=max(maxi,op3);
	return maxi;
}
class Pair{
public:
	int height;
	int diameter;
};
Pair diameteroptimized(node*root){
	Pair p;
	if(root==NULL){
		p.height=0;
		p.diameter=0;
		return p;
	}
	Pair left=diameteroptimized(root->left);
	Pair right=diameteroptimized(root->right);

	p.height=max(left.height,right.height)+1;
	p.diameter=max(left.height+right.height,max(left.diameter,right.diameter));
	return p;

}

int main(){	
	node*root=buildtree();
	Pair p=diameteroptimized(root);
	cout<<p.diameter<<endl;
	return 0;
}