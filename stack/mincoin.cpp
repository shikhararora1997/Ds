#include<iostream>
using namespace std;

int getmincoin(int n,int *ar,int *lookup){

	if(n==0)
		return 0;
	if(lookup[n]!=0)
		return lookup[n];	
	int res=0;

	if(n-ar[0]>=0) 
		res=getmincoin(n-ar[0],ar,lookup);

	if(n-ar[1]>=0 && getmincoin(n-ar[1],ar,lookup)<res)
	    res=getmincoin(n-ar[1],ar,lookup);

	if(n-ar[2]>=0 && getmincoin(n-ar[2],ar,lookup)<res)
	    res=getmincoin(n-ar[2],ar,lookup);

	lookup[n]=res+1;
	return lookup[n];
}
int main(){
	int n;
	cin>>n;			//10
	int ar[3];
	for(int i=0;i<3;i++)
		cin>>ar[i];		//3 5 6	
	int lookup[n];
	for(int i=0;i<n;i++)
		lookup[n]=0;
	cout<<getmincoin(n,ar,lookup)<<endl;
	cout<<lookup[1];
	return 0;
}