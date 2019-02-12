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
void detectloopandremove(node*&head){
    node*fast=head;
    node*slow=head;

    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
            break;
        }
    }
    if(slow==fast){
        slow=head;
        while(slow->next!=fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        fast->next=NULL;
    }
}
bool detectcycle(node*head){
    node*fast=head;
    node*slow=head;

    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
            return true;
        }
    }
    return false;
}
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

int main(){
	node*head1=NULL;
    node*head2=NULL;
    node*head;
    buildlist(head1);
    buildlist(head2);
	printnode(head);
	
	
	return 0;
}