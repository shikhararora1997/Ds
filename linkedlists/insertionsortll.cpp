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
    if(n==0){
        return NULL;
    }
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

node*sortit(node*head){
   node*sorted=NULL;
   node*curr=head;

   while(curr!=NULL){
       node*next=curr->next;
       
       if(sorted=NULL) || sorted->data>curr->data){
           curr->next=sorted;
           sorted=curr;
        }
        else{
            node*temp=sorted;
            while(temp->data>curr->data && temp->next!=NULL){
                temp=temp->next;
            }
            curr->next=temp;
            
        }

   }
}
int main(){
    int n;
    cin>>n;
    node*head=buildlist(n);
    node*newhead=sortit(head);
    return 0;
}
