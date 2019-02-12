#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t!=0){
        int n;
        cin>>n;
        int ar[n];
        int dp[n];
        for(int i=0;i<n;i++){
            cin>>ar[i];
            dp[i]=1;
        }
        int best=-1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(ar[i]>ar[j]){
                    int curlen=dp[j]+1;
                    dp[i]=max(curlen,dp[i]);
                }
            }
            best=max(best,dp[i]);
        
        }
        cout<<best<<endl;
    t--;
    }
    
    return 0;
}