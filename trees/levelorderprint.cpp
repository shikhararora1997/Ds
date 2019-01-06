//complexity is o(n sqr)
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
void printKthlevel(node*root,int k){
	if(root==NULL)
		return;
	if(k==1){
		cout<<root->data<<" ";
		return;
	}
	printKthlevel(root->left,k-1);
	printKthlevel(root->right,k-1);
	return;

}
int main(){	
	node*root=buildtree();
	int h=height(root);
	for(int i=0;i<=h;i++){
		printKthlevel(root,i);
		cout<<endl;
	}


	return 0;
}