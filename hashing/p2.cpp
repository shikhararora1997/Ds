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
node* perform(node*head,int k,int n){
    if(head==NULL)
        return NULL;
    node*temp=head;
    int c=0;
    if(n!=k){
    while(c<n-k-1){
        temp=temp->next;
        c++;
    }
    node*second=temp->next;
    node*newhead=temp->next;
    temp->next=NULL;
    while(second->next!=NULL){
        second=second->next;
    }
    second->next=head;
    return newhead;
    }
    else{
        return head;
    }
}


int main(){
    int n;
    cin>>n;
    node*head=buildlist(n);
    int k;
    cin>>k;
    node*ans=perform(head,k,n);
    printnode(ans);

    return 0;
}