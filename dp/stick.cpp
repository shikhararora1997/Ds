#include<iostream>
using namespace std;
int memo[1000];
int getmax(int*cost,int length,int*memo){
    if(length==0){
        return cost[0];
    }
    if(memo[length]!=-1){
        return memo[length];
    }
    int best=0;
    for(int i=0;i<=length;i++){
        int profit= cost[i]+getmax(cost,length-i-1,memo);
        best=max(profit,best);
    }
    memo[length]=best;

    return best;
}


int main(){
    memset(memo,-1,sizeof(memo));
    int cost[]={4,7,6,8};
    cout<<getmax(cost,3,memo);

    return 0;
}