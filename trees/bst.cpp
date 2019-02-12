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
bool search(node*root,int d){
	if(root==NULL)
		return false;
	if(root->data==d)
		return true;
	if(root->data>=d)
		return search(root->left,d);
	else
		return search(root->right,d);
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
 bool isbst(node*root,int min=INT_MIN,int max=INT_MAX){
	if(root==NULL)
 		return true;

 	if(root->data>=min && root->data<=max && isbst(root->left,min,root->data) && isbst(root->right,root->data,max))
		return true;
	return false;
	 }

int main()
{
	node*root=build();
	bfs(root);
	cout<<search(root,5)<<endl;
	if(isbst(root))
		cout<<"It is a BST"<<endl;
	else
		cout<<"It is not a BST"<<endl;

	return 0;
}