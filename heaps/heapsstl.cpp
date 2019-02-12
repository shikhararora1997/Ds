#include<iostream>
#include<queue>
#include<vector>
#include<functional>
using namespace std;

int main(){
	//max heap
	priority_queue<int> pq;
	//min heap
	priority_queue<int,vector<int>,greater<int> > pq2;;
	int a[10]={5,6,7,8,9,10};
	for(int i=0;i<6;i++){
			pq.push(a[i]);
			pq2.push(a[i]);
   	}
   	while(!pq.empty()){
   		cout<<pq.top()<<",";
   		pq.pop();
   	}
   	cout<<endl;
   	while(!pq2.empty()){
   		cout<<pq2.top()<<",";
   		pq2.pop();
   	}

return 0;
}