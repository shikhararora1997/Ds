#include<iostream>
#include<queue>
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



node*createtree(int*pre,int*in,int s,int e){
	if(s>e)
		return NULL;
	static int i=0;
	int index=-1;
	node*root=new node(pre[i]);
	for(int j=s;j<= e;j++){
		if(in[j]==pre[i]){
			index=j;
			break;
		}
	}
	i++;
	root->left=createtree(pre,in,s,index-1);
	root->right=createtree(pre,in,index+1,e);
	return root;
}


bool isbst(node*root,int min=INT_MIN,int max=INT_MAX){
	if(root==NULL)
 		return true;

 	if(root->data>=min && root->data<=max && isbst(root->left,min,root->data) && isbst(root->right,root->data,max))
		return true;
	return false;
	 }

int count(node*root){
	if(root==NULL)
		return 0;
	return 1+count(root->left)+count(root->right);
}
int sizebst(node*root){

	if(root==NULL)
		return 0;


	if(isbst(root)){
		return count(root);
	}
	else{
		return max(sizebst(root->left),sizebst(root->right));
	}
}
int main(){
	int pre[]={50,30,5,20,60,45,70,65,80};
	int in[]={5,30,20,50,45,60,65,70,80};

	node*root=createtree(pre,in,0,8);
	
	int size=sizebst(root);
	cout<<size;
	
	return 0;
}