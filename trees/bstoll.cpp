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

class Linkedlist{

public:
	node*head;
	node*tail;
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


Linkedlist flatten(node*root){
	Linkedlist ll;
	if(root==NULL){
			ll.head=NULL;
			ll.tail=NULL;
			return ll;
		}
	if(root->left==NULL && root->right==NULL){
			ll.head=root;
			ll.tail=root;
			return ll;
	}
	if(root->left!=NULL && root->right==NULL){
			Linkedlist leftll=flatten(root->left);
			leftll.tail->right=root;
			ll.head=leftll.head;
			ll.tail=root;
			return ll;
	}
	if(root->left==NULL && root->right!=NULL){
		Linkedlist rightll=flatten(root->right);
		root->right=rightll.head;
		ll.head=root;
		ll.tail=rightll.tail;
		return ll;
	}
		Linkedlist leftll=flatten(root->left);
		Linkedlist rightll=flatten(root->right);
		leftll.tail->right=root;
		root->right=rightll.head;
		ll.head=leftll.head;
		ll.tail=rightll.tail;
		return ll;
	
}


int main(){
	node*root=build();
	bfs(root);
	cout<<endl;
	Linkedlist l=flatten(root);
	node*temp=l.head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->right;
	}
	return 0;
}





