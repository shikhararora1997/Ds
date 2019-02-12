#include<iostream>
using namespace std;

int dp[1000][10000];
int csum(int*ar,int i,int k){
    int sum=0;
    for(int s=i; s <= k; s++)
    {
        sum=sum+ar[s];
        sum=sum%100;
    }
    return sum;
    
}
int solve(int*ar,int i,int j){

    if (i>=j) {
        return 0;
    }
    if(dp[i][j]!=-1)return dp[i][j];


   

    for(int k=i;k<=j;k++){
        dp[i][j]=solve(ar,i,k)+solve(ar,k+1,j)+csum(ar,i,k)*csum(ar,k+1,j);
    }
    return dp[i][j];
}
int main(){
    int n;
    cin>>n;
    int ar[n];
    memset(dp,-1,sizeof(dp));

    
    for(int i=0;i<n;i++)cin>>ar[i];

    cout<<solve(ar,0,n-1);
    return 0;
}