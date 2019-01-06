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
class HBpair{
public:
	bool balanced;
	int height;
};
HBpair checkhb(node*root){
	HBpair p;
	if(root==NULL){
		p.height=0;
		p.balanced=true;
		return p;
	}
	HBpair left=checkhb(root->left);
	HBpair right=checkhb(root->right);
	p.height=max(left.height,right.height)+1;

	if(abs(left.height-right.height)<=1 && left.balanced && right.balanced){
		p.balanced=true;
	}
	else
		p.balanced=false;
	return p;

}
int main(){
	node*root=buildtree();
	cout<<endl;
	HBpair ans;
	ans=checkhb(root);
	cout<<ans.balanced<<endl;
	return 0;
}