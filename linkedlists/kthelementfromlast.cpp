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

void printnode(node*head){
	if(head==NULL)
		return;
	while(head!=NULL){
		cout<<head->data<<" ";
		head=head->next;
	}
}

void kthpos(node*head,int k){
    if(head==NULL){
        return;
    }
    node*fast=head;
    int cnt=0;
    while(cnt<k){
        fast=fast->next;
        cnt++;
    }
    node*slow=head;
    while(fast!=NULL){
        slow=slow->next;
        fast=fast->next;
    }
    cout<<slow->data;
    return;
}
int main(){
    node*head;
    int d;
    cin>>d;
    if(d!=-1){
        head=new node(d);
    }
    else{
        return 0;
    }
    node*temp=head;
    int x;
    cin>>x;
    while(x!=-1){
        node*newnode=new node(x);
        temp->next=newnode;
        temp=temp->next;
        cin>>x;
    }
    temp->next=NULL;
    int k;
    cin>>k;
    kthpos(head,k);
    return 0;
}