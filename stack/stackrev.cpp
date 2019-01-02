#include<iostream>
#include<stack>
#include<cstring>

using namespace std;

/*
void reversestack(stack<int> s){
	stack<int> temp;
	while(!s.empty()){
		temp.push(s.top());
		s.pop();
	}
	while(!temp.empty()){
		cout<<temp.top();
		temp.pop();
	}
	cout<<endl;
}*/
void insertatbottom(stack<int> &s,int x){
	if(s.empty()){
		s.push(x);
		return;
	}
	int y=s.top();
	s.pop();
	insertatbottom(s,x);
	s.push(y);
}
void stackrecrev(stack<int> &s){
	if(s.empty()) return;
	int x;
	x=s.top();
	s.pop();
	stackrecrev(s);
	insertatbottom(s,x);
}

int main(){
	stack<int> s;
	stack<int> temp;

	s.push(5);
	s.push(4);
	s.push(3);
	s.push(2);
	s.push(1);
	stackrecrev(s);
	while(!s.empty()){
		cout<<s.top();
		s.pop();
	}
	return 0;
}