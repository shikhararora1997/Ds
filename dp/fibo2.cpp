#include<iostream>
using namespace std;

int memo[10000];

int main(){
    int n;
    cin>>n;
     memo[0]=0;
    memo[1]=1;
    for(int i=2;i<10000;i++){
        memo[i]=memo[i-1]+memo[i-2];
    }
    cout<<memo[n];
    return 0;
}

