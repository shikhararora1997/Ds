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
node*hbtree(int*a,int s,int e){
	if(s>e)
		return NULL;
	int mid=(s+e)/2;
	node*root=new node(a[mid]);
	root->left=hbtree(a,s,mid-1);
	root->right=hbtree(a,mid+1,e);
	return root;
}
int main(){
	// node*root=buildtree();
 	// cout<<endl;
	// HBpair ans;
	// ans=checkhb(root);
	// cout<<ans.balanced<<endl;
		int ar[11]={0};
		for(int i=0;i<11;i++)
		cin>>ar[i];
	node*root=hbtree(ar,0,10);
		
	bfs(root);
	return 0;
}