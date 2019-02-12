#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;

void query(priority_queue<int> pq){

	while(!pq.empty()){
		cout<<pq.top()<<",";
		pq.pop();
	}
	cout<<endl;
}
int main(){
	int no;
	priority_queue<int> pq;
	int cs=0;
	int k=3;
	while(scanf("%d",&no)!=EOF){
		if(no==-1){
			query(pq);
		}
		else if(cs<k){
			pq.push(no);
			cs++;
		}
		else{
			if(no>pq.top()){
				pq.pop();
				pq.push(no);
			}
		}
	}


	return 0;
}