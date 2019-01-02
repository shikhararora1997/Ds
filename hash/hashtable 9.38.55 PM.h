#include<cstring>
#include<iostream>

using namespace std;

class  Node{
public:
	string key;
	int value;
	Node*next;

	Node(string k,int v){
		key=k;
		value=v;
		next=NULL;
	}
};
class Hashtable{
	Node**table;
	int cs;
	int ts;
  
    //formula + Step Wise Modulo to avoid overflow
	int hashFn(string key){
		int idx=0;
		int p=1;
		for(int i=0;i<key.length();i++){
			idx=idx+(p*key[i]);
			p=(p*37)%ts;

		}
		return idx%ts;
	}
	//(A+b)%m=(A%m+b%m)%m
public:
	Hashtable(int ds=7){
		ts=ds;
		table=new Node*[ts];
		//Create and Init table
		for(int i=0;i<ts;i++){
			table[i]=NULL;
		}
	}
	void insert(string key,int value){
		int idx=hashFn(key);
		Node *n=new Node(key,value);
		n->next=table[idx];
		table[idx]=n;
		cs++;
	}
	void print(){
		for(int i=0;i<ts;i++){
			cout<<"Bucket"<<i<<"-->";
			Node *temp=table[i];
			while(!temp){
				cout<<temp->key<<",";
				temp=temp->next;
		}
		cout<<endl;
	}
}
};