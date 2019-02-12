
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

// int main()
// {

//     int t;
//     cin >> t;
//     while(t--)
//     {
//         int n,m;
//         cin >> n >> m;
//         int dp[n+1][m+1];
//         string s1,s2;
//         cin >> s1 >> s2;
//         for(int i = 0;i<=n;i++)
//             dp[i][0] = i;
//         for(int i =0;i<=m;i++)
//             dp[0][i] = i;
//         for(int i = 1;i<=n;i++)
//         {
//             for(int j = 1;j<=m;j++)
//             {
//                 if(s1[i-1] == s2[j-1])
//                     dp[i][j] = dp[i-1][j-1];
//                 else
//                     dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j], dp[i][j-1])) + 1;
//             }
//         }
//         for(int i=0;i<n+1;i++){
//             for(int j=0;j<m+1;j++){
//                 cout<<dp[i][j]<<" ";
//             }
//             cout<<endl;
//         }
//         cout << dp[n][m] << endl;
//     }

//     return 0;
// }


int getmindist(string s,string s1,int i,int j,int l1,int l2){
    if(i>l1)return l2-j+1;
    if(j>l2)return l1-i+1;

    if(l1==0){
        return l2;
    }
    if(l2==0){
        return l1;
    }
                        
    if(s[i]==s1[j]){
       
        return getmindist(s,s1,i+1,j+1,l1,l2);
    }
    return 1+min(getmindist(s,s1,i+1,j,l1,l2),min(getmindist(s,s1,i,j+1,l1,l2),getmindist(s,s1,i+1,j+1,l1,l2)));
}
int main(){
    
    string s;
    string s1;
    cin>>s;
    cin>>s1;
    
    cout<<getmindist(s,s1,0,0,s.length(),s1.length());
    return 0;
}



#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int dp[100][100];
int getmindist(string s,string s1,int i,int j,int l1,int l2){
    if(i>l1)return 0;
    if(j>l2)return 0;

    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(l1==0){
        return l2;
    }
    if(l2==0){
        return l1;
    }
  
    if(s[i]==s1[j]){
        int x=getmindist(s,s1,i+1,j+1,l1,l2);
        dp[i][j]=x;
        return x;
    }
    int x=min(getmindist(s,s1,i+1,j,l1,l2),min(getmindist(s,s1,i,j+1,l1,l2),getmindist(s,s1,i+1,j+1,l1,l2)));
    dp[i][j]=x+1;
    return 1+x;
}
int main(){
    
    string s;
    string s1;
    cin>>s;
    cin>>s1;
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            dp[i][j]=-1;
        }
    }
    cout<<getmindist(s,s1,0,0,s.length(),s1.length());
    return 0;
}

