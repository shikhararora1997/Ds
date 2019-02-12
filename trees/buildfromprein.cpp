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

node*createtree(int*pre,int*in,int s,int e){
	if(s>e)
		return NULL;
	static int i=0;
	
	node*root=new node(pre[i]);
	int j;
	for(j=s;j<= e;j++){
		if(in[j]==pre[i]){
			
			break;
		}
	}
	i++;
	root->left=createtree(pre,in,s,j-1);
	root->right=createtree(pre,in,j+1,e);
	return root;
}


int main(){
	int pre[]={1,2,3,4,8,5,6,7};
	int in[]={3,2,8,4,1,6,7,5};

	node*root=createtree(pre,in,0,7);
	bfs(root);
	
	return 0;
}