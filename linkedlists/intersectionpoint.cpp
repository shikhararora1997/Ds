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

int getcount(node*head){

    int s=0;
    while(head!=NULL){
        s++;
        head=head->next;
    }
    return s;
}

void findintersection(node*head1,node*head2){
    
    int m=getcount(head1);
    int l=0;
    int n=getcount(head2);
    if(m>n){
        while(m!=n){
        head1=head1->next;
        m--;
        }
        
        while(head1!=NULL){
            if(head1->data==head2->data){
                cout<<head1->data;
                l=1;
                break;
            }
            head1=head1->next;
            head2=head2->next;
        }
    }
    else{
        while(m!=n){
        head2=head2->next;
        n--;
        }
       
        while(head1!=NULL){
            if(head1->data==head2->data){
                cout<<head1->data;
                l=1;
                break;
            }
            head1=head1->next;
            head2=head2->next;
        }

    }
    if(l==0){
        cout<<-1;
    }
}

int main(){ 
    int a;
    cin>>a;
    node*head1=buildlist(a);
    int b;
    cin>>b;
    node*head2=buildlist(b);
    findintersection(head1,head2);
    return 0;
}