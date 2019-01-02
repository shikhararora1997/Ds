#include<iostream>
using namespace std;

template<typename T>
class Queue{
private:
	T* arr;
	int f;
	int r;
	int cs;
	int ms;
public:
	Q#include <.h>ueue(int x=10){
		f=0;
		ms=x;
		r=ms-1;
		arr=new T[ms];
		cs=0;
	}
	bool isFull(){
	return cs==ms;
	}
	bool isEmpty(){
	return cs==0;
	}
    void push(T data){
    	 r=(r+1)%ms;
    	 arr[r]=data;
    	 cs++;
    }
    void pop(){
    	f=(f+1)%ms;
    	cs--;
    }
    T getFront(){
    	return arr[f];
    }
};
int main(){
	
	Queue<int> q;
	q.push(1);
	q.push(2);v
	while(!q.isEmpty()){
		cout<<q.getFront();
		q.pop();
	}
	


	return 0;
}