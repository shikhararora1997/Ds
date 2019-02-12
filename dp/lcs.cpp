

// #include <iostream>
// #include <string>
// using namespace std;

// int findmax(string s1,string s2,int m,int n,int i,int j,int dp[101][101]){
//     if(m==0 || n==0)return 0;
//     if(i>=m || j>=n)return 0;

//     if(dp[i][j]!=-1)return dp[i][j];
    
//     if(s1[i]==s2[j]){
//         int x=1+findmax(s1,s2,m,n,i+1,j+1,dp);
//         dp[i][j]=x;
//         return x;
//     }
//     int y=max(findmax(s1,s2,m,n,i+1,j,dp),findmax(s1,s2,m,n,i,j+1,dp));
//     dp[i][j]=y;
//     return y;
// }

// int main() {
// 	//code
// 	int t;
// 	cin>>t;
// 	while(t!=0){
// 	    int dp[101][101];
//         for(int i=0;i<101;i++){
//             for(int j=0;j<101;j++){
//                 dp[i][j]=-1;
//             }
//         }
// 	    int m;int n;string s1;string s2;
// 	    cin>>m;cin>>n;
// 	    cin>>s1;cin>>s2;
// 	    cout<<findmax(s1,s2,m,n,0,0,dp)<<endl;
// 	    t--;
// 	}
// 	return 0;
// }




#include <iostream>
#include <string>
using namespace std;

int findmax(string s1,string s2,int m,int n){

    int dp[1000][1000];
    for(int i=0;i<=m;i++)dp[0][i]=0;
    for(int j=0;j<=n;j++)dp[j][0]=0;

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
                break;
            }
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[m][n];
}

int main() {
	//code
	int t;
	cin>>t;
	while(t!=0){
	    int m;int n;string s1;string s2;
	    cin>>m;cin>>n;
	    cin>>s1;cin>>s2;
	    cout<<findmax(s1,s2,m,n)<<endl;
	    t--;
	}
	return 0;
}