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
node*kappend(node*head,int k,int s){
    if(k==s){
        return head;
    }
    
    if(k>s){
        k=k%s;
    }
    
    node*temp=head;
    int cnt=0;
    while(cnt!=s-k-1){
        temp=temp->next;
        cnt++;
    }
    node*temp2=temp->next;
    temp->next=NULL;
    node*newhead=temp2;
    while(temp2->next!=NULL){
        temp2=temp2->next;
    }
    temp2->next=head;
    head=newhead;
    return head;
 }
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
int main(){
    int n;
    cin>>n;
    node*head=buildlist(n);
    int k;
    cin>>k;
    node*newhead=kappend(head,k,n);
    printnode(newhead);
    return 0;
}

