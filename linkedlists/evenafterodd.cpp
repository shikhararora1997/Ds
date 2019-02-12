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
node*buildlist(int n){
    int d;
    cin>>d;
    node*head=new node(d);
    node*temp=head;
    int c=1;
    while(c<n){
        cin>>d;
        node*temp2=new node(d);
        temp->next=temp2;
        temp=temp2;
        c++;
    }
    temp->next=NULL;
    return head;
}
void printnode(node*head){
	if(head==NULL)
		return;
	while(head!=NULL){
		cout<<head->data<<" ";
		head=head->next;
	}
}
node*evenafterodd(node*head,int n){
    
    node*evenstart=NULL;
    node*evenend=NULL;
    node*oddstart=NULL;
    node*oddend=NULL;
    node*curnode=head;

    while(curnode!=NULL){
        int val=curnode->data;
        if(val%2!=0){
            if(oddstart==NULL){
                oddstart=curnode;
                oddend=curnode;
            }
            else{
                oddend->next=curnode;
                oddend=oddend->next;
            }
        }
        else{
            if(evenstart==NULL){
                evenstart=curnode;
                evenend=curnode;
            }
            else{
                evenend->next=curnode;
                evenend=evenend->next;
            }
        }
        curnode=curnode->next;
    }
    if(oddstart==NULL || evenstart==NULL){
        return head;
    }
   
        oddend->next=evenstart;
        evenend->next=NULL;
        head=oddstart;
        return head;
    
}
int main(){
    int n;
    cin>>n;
    node*head=buildlist(n);
    node*newhead=evenafterodd(head,n);
    printnode(newhead);
    return 0;
}

