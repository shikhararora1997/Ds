#include<iostream>
#include<stack>
#include<array>
using namespace std;

stack<int> s;
void solve(int *ar,int n){
    int sol[n];
	for(int i=n-1;i>=0;i--){

		while(!s.empty() && ar[i]>s.top())
			s.pop();

		if(s.empty())
			sol[i]=-1;
		else
			sol[i]=s.top();

		s.push(ar[i]);

	}
    for(int i=0;i<n;i++)
		cout<<sol[i]<<" ";
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	solve(arr,n);
}