#include<iostream>
#include<queue>
#include<vector>
#include<utility>
using namespace std;

int rocket(int a,int b){
	return a*a+b*b;
}
void query(priority_queue<int> pq){

		cout<<pq.top()<<endl;
		pq.pop();
}
int main(){

	int t;
	cin>>t;
	int k;
	cin>>k;
	priority_queue<int> pq;
	int cs=0;
	while(t>0){
		int q;
		cin>>q;
		if(q==1){
				int a;
				int b;
				cin>>a;
				cin>>b;
				if(cs<k){
					pq.push(rocket(a,b));
					cs++;
				}
				else{
					if(rocket(a,b)<pq.top()){
						pq.pop();
						pq.push(rocket(a,b));
					}
				}
		}
		if(q==2){
			query(pq);
		}
		t--;
	}
	return 0;
}