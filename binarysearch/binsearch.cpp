#include<iostream>
using namespace std;


int find(int *ar,int beg,int end){
	int mid=(beg+end)/2;
	while(beg<=end){
		int mid=(beg+end)/2;

		if(ar[mid]>=2){
			ans=mid;
			end=mid-1;;
		}
		else if(a[mid]>key){	
			end=mid-1;
		}
		mid=(beg+end)/2;
	}
	return beg;
}
int main(){
	int arr[11]={0,0,1,1,2,2,2,3,5,7,9};
	cout<<find(arr,0,10);
	return 0;
}