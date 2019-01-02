#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main() {
  stack<int> s;
  string c;
  cin>>c;
  for(int i=0;i<c.length();i++){
    if(c[i]=='{')
      s.push(1);
    else if(!s.empty() && c[i]=='}')
        s.pop();
    else if(s.empty() && c[i]=='}' )
    {
      cout<<"No"<<endl;
      return 0;
    }
    
  }
  cout<<"Yes"<<endl;
  
  
	return 0;
}