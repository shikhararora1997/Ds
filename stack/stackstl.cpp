#include<iostream>
#include<stack>
#include<cstring>

using namespace std;


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
}

int main(){
	stack<int> s;
	stack<int> temp;

	s.push(5);
	s.push(4);
	s.push(3);
	s.push(2);
	s.push(1);
	reversestack(s);
	
	return 0;
}