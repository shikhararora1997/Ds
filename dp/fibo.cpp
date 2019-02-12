#include<iostream>
using namespace std;
int memo[10000];
int fib(int n){
    if(n==1) return 0;
    if(n==2) return 1;

    if(memo[n]!=-1){
        return memo[n];
    }
    memo[n]=fib(n-1)+fib(n-2);
    return fib(n-1)+fib(n-2);
}

int main(){

    int n;
    cin>>n;
    memset(memo,-1,sizeof(memo));
    cout<<fib(n);

    return 0;
}