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

node*getreebetter(int*pre,int key,int min,int max,int n){
	static int i=0;
	
	if(i>n)
		return NULL;
	node*root=NULL;
	if(key>min && key<max){
		root=new node(pre[i]);
		i++;
		if(i<n){
			root->left=getreebetter(pre,pre[i],min,key,n);
			root->right=getreebetter(pre,pre[i],key,max,n);
		}

	}
	return root;
}

node*getree(int*pre,int s,int e){
	if(s>e){
		return NULL;
	}

	int j;
					
	node*root=new node(pre[s]);
	for(j=s+1;j<=e;j++){
		if(pre[j]>pre[s]){
			break;
		}
	}

	root->left=getree(pre,s+1,j-1);
	root->right=getree(pre,j,e);
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
}

int main(){
	int pre[]={5,3,1,7,6,8};
	node*root=getree(pre,0,5);
	bfs(root);
	cout<<endl;
	node*root2=getreebetter(pre,pre[0],INT_MIN,INT_MAX,6);
	bfs(root2);
	return 0;
}