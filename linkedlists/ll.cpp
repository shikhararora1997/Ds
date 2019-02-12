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
/*
class Linkedlist{
	node*head;
	node*tail;
public:
	Linkedlist(){
		head=NULL;
		tail=NULL:
	}
};
*/
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
void deletehead(node*&head){

	if(head==NULL){
		return;
	}
	node*temp=head;
	head=head->next;
	delete temp;

}
void buildlist(node*&head){
	int data;
	cin>>data;

	while(data!=-1){
		insertathead(head,data);
		cin>>data;
	}
}
void reversell(node*&head){
	node*prev=NULL;
	node*curr=head;
	node*temp=NULL;
	while(curr!=NULL){
		temp=curr->next;
		curr->next=prev;
		prev=curr;
		curr=temp;
	}
	head=prev;
}

void kthfromend(node*head,int k){
	node*fast=head;
	node*slow=head;
	int cnt=0;
	while(cnt<k){
		fast=fast->next;
		cnt++;
	}
	while(fast!=NULL && fast->next!=NULL){
		fast=fast->next;
		slow=slow->next;
	}
	cout<<slow->data;

}
int main(){
	node*head=NULL;
	buildlist(head);
	printnode(head);
	cout<<endl;
	kthfromend(head,2);
	
	return 0;
}