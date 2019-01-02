#include<iostream>
#include<deque>
using namespace std;
void operate(int*a,int s,int k){

	deque<int> l(k);
	for(int i=0;i<k;i++){
		while(!l.empty() && a[l.back()]<a[i]){
			l.pop_back();
		}
		l.push_back(i);
	}
	for(int i=k;i<s;i++){
		cout<<a[l.front()]<<" ";
		while(!l.empty() && a[l.front()]<=i-k)
			l.pop_front();
		while(!l.empty() && a[l.back()]<a[i])
			l.pop_back();
		l.push_back(i);
	}
	cout<<a[l.front()];
}

int main(){
	int n;
	cin>>n;
	int ar[n];
	for(int i=0;i<n;i++)
		cin>>ar[i];
	int k;
	cin>>k;
	operate(ar,n,k);

	return 0;
}