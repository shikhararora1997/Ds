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
node*reverse(node*head){
    node*prev=NULL;
    node*curr=head;
    node*temp=NULL;
    while(curr!=NULL){
        temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    return prev;
}
bool palindrome(node*head,int n){
    if(head==NULL){
        return false;
    }
    node*temp=head;
    
    if(head==NULL)
        return false;
    if(n%2!=0){             
        int k=n/2;          
        while(k!=0){
            temp=temp->next;
            k--;
        }
    }
    else{
        int k=n/2;              
        while(k!=1){
            temp=temp->next;
            k--;
        }
    }
    node*newll=reverse(temp->next);
    while(newll!=NULL){
        if(newll->data!=head->data)
            return false;
        newll=newll->next;
        head=head->next;
    }
    return true;
}




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
int main(){
    int n;
    cin>>n;
    node*head=buildlist(n);
    bool x=palindrome(head,n);
    if(x==0){
        cout<<"false";
    }
    else
    {
        cout<<"true";
    }
    
    return 0;
}
