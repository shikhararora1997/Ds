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

void bfs(node*root){
	queue<node*> q;
	q.push(root);


	while(!q.empty()){
		node*f=q.front();
		cout<<f->data<<",";
		q.pop();
		if(f->left)
			q.push(f->left);
		if(f->right)
			q.push(f->right);
	}
	return;
}
void bfswithlb(node*root){
	queue<node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		node*f=q.front();
		if(f==NULL){
			cout<<endl;
			q.pop();
			if(!q.empty()){
				q.push(NULL);
			}
		}
		cout<<f->data<<",";
		q.pop();
			if(f->left)
			q.push(f->left);
		if(f->right)
			q.push(f->right);
	}
	return;
	}
int count(node*root){
	if(root==NULL)
		return 0;
	return 1+count(root->left)+count(root->right);
}
int sumof(node*root){
	if(root==NULL)
		return 0;
	return root->data+sumof(root->left)+sumof(root->right);
}

node* hbtree(int*ar,int s,int e){
	if(s>e)
		return NULL;
	int mid=(s+e)/2;
	node*root=new node(a[mid]);
	root->left=hbtree(a,s,mid-1);
	root-<right=hbtree(a,mid+1,e);
	return root;
}
int main(){
	node*root=buildtree();
	bfs(root);
	cout<<endl;
	cout<<count(root)<<endl;
	cout<<sumof(root)<<endl;
}