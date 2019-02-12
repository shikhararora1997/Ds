#include<iostream>
using namespace std;

int findmax(int*ar1,int*ar2,int m,int n,int i,int j,int k,int dp[1000][1000][100]){
    if(m==0 || n==0)return 0;
    if(i>=m || j>=n)return 0;
    
    if(dp[i][j][k]!=-1)return dp[i][j][k];

    if(ar1[i]==ar2[j]){
        int x=1+findmax(ar1,ar2,m,n,i+1,j+1,k,dp);
        dp[i][j][k]=x;
        return x;
    }
    else{
    int y=1+findmax(ar1,ar2,m,n,i+1,j+1,k-1,dp);
    int w=findmax(ar1,ar2,m,n,i+1,j,k,dp);
    int z=findmax(ar1,ar2,m,n,i,j+1,k,dp);
    m=max(y,max(w,z));
    dp[i][j][k]=m;

    return m;
    }
}

int main(){
    int t;
    cin>>t;

    while(t!=0){
        int m;int n;int k;
        cin>>m;cin>>n;cin>>k;
        int ar1[m];int ar2[n];
        for(int i=0;i<m;i++){
            cin>>ar1[i];
        }
        for(int i=0;i<m;i++){
            cin>>ar2[i];
        }
        int dp[1000][1000][100];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(int m=0;m<k;m++){
                dp[i][j][m]=-1;
                }
            }
        }
        cout<<findmax(ar1,ar2,m,n,0,0,k,dp);
     t--;
    }

    return 0;
}