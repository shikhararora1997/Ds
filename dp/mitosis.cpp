#include<iostream>
using namespace std;

int dp[1000];int x;int y;int z;int n;
int solve(){
    dp[0]=0;
    dp[1]=0;

    for(int i=2;i<=n;i++){
        if(i%2==0){
            dp[i]=min(dp[i/2]+x,dp[i-1]+y);
        }
        else{
            dp[i]=min(dp[i-1]+y,dp[(i+1)/2]+x+z);
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}
int main(){

  cin>>n;cin>>x;cin>>y;cin>>z;
  
  solve();
  return 0;
}