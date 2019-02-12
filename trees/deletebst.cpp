#include<iostream>
#include<queue>
using namespace std;

class node{
public:
	int data;
	node*right;
	node*left;
	node(int d){
		right=NULL;
		left=NULL;
		data=d;
	}

};
node*buildbst(node*root,int d){
	if(root==NULL)
		return new node(d);
	if(d<=root->data)
		root->left=buildbst(root->left,d);
	else
		root->right=buildbst(root->right,d);


	return root;
}
node*build(){
	int d;
	cin>>d;
	node*root=NULL;
	while(d!=-1){
		root=buildbst(root,d);
		cin>>d;
	}
	return root;
}

void bfs(node*root){
	queue<node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		node*f=q.front();
		if(f==NULL){
			cout<<endl;
			q.pop();
			if(!q.empty())
				q.push(NULL);
		}
		else{
		cout<<f->data<<",";
		q.pop();
		if(f->left)
			q.push(f->left);
		if(f->right)
			q.push(f->right);
	}
	
	}
	return;
}

node*deletebst(node*root,int data){
	
	if(root==NULL)
		return NULL;
	else if(data>root->data){
		root->right=deletebst(root->right,data);
		return root;
	}

	else if(data==root->data){
		if(root->left==NULL && root->right==NULL){
			delete root;
			return NULL;
		}
		if(root->left!=NULL && root->right==NULL){
			node*temp=root->left;
			delete root;
			return temp;
		}
		if(root->left==NULL && root->right!=NULL){
			node*temp=root->right;
			delete root;
			return temp;
		}
		if(root->left!=NULL && root->right!=NULL){
			node*replace=root->right;
			while(replace->left!=NULL){
				replace=replace->left;
			}
			root->data=replace->data;
			root->right=deletebst(root->right,replace->data);
			return root;
		}
	}
	else{
		root->left=deletebst(root->left,data);
		return root;
	}
}


int main(){

	node*root=build();
	bfs(root);
	deletebst(root,1);
	cout<<endl;
	bfs(root);

	return 0;
}