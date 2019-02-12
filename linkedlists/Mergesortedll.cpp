#include<iostream>
using namespace std;

class node{
public:
	int data;
	node*next;

	node(int d){
		data=d;
		next=NULL;
	}
};

void insertathead(node*&head,int d){
	node*newnode=new node(d);
	newnode->next=head;
	head=newnode;
}

void printnode(node*head){
	if(head==NULL)
		return;
	while(head!=NULL){
		cout<<head->data<<" ";
		head=head->next;
	}
}
void buildlist(node*&head){
	int data;
	cin>>data;

	while(data!=-1){
		insertathead(head,data);
		cin>>data;
	}
}
node* merge(node*a,node*b){
    
    if(a==NULL){
        return b;
    }
    else if(b==NULL){
        return a;
    }
    node*c;
    if(a->data < b->data){
        c=a;
        c->next=merge(a->next,b);
    }
    else
    {
        c=b;
        c->next=merge(a,b->next);
    }
    return c;
    
}


int main(){
	node*head1=NULL;
    node*head2=NULL;
    node*head;
    buildlist(head1);
    buildlist(head2);
    head=merge(head1,head2);
	printnode(head);
	
	
	return 0;
}