#include<iostream>
using namespace std;
int memo[1000][1000];
int getprofit(int*arr,int beg,int end,int year){
    if(beg>end)
        return 0;
    if(memo[beg][end]!=-1)return memo[beg][end];
    int a=arr[beg]*year+getprofit(arr,beg+1,end,year+1);
    int b=arr[end]*year+getprofit(arr,beg,end-1,year+1);
    memo[beg][end]=max(a,b);
    return max(a,b);
}
int main(){
    
    int arr[5]={2,3,5,1,4};
    for(int i=0;i<1000;i++){
        for(int j=0;j<1000;j++){
            memo[i][j]=-1;
        }
    }
    cout<<getprofit(arr,0,4,1);
    return 0;
}