#include<iostream>
#include<queue>
#include<functional>
#include<vector>
using namespace std;

class car{
public:
	int x;
	int y;
	int id;
	car(int id,int x,int y){
		this->id=id;
		this->x=x;
		this->y=y;
	}
	int dist(){
		return x*x+y*y;
	}
	void print(){
		cout<<id<<endl;
	}
};
class carcompare{
public:
	bool operator()(car a,car b){
		return a.dist()>b.dist();
	}
};
int main(){

	priority_queue<car,vector<car>,carcompare>  pq;
	int x[10]={5,2,6,3,1,2,7,8,9,10};
	int y[10]={4,6,7,2,3,9,10,10,2,4};

	for(int i=0;i<10;i++){
		car c(i,x[i],y[i]);
		pq.push(c);
	}
	while(!pq.empty()){
		car p=pq.top();
		p.print();
   		pq.pop();
   	}
   	return 0;

}