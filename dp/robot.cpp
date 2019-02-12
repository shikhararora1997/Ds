#include<iostream>
#include<cstring>
using namespace std;
#define ll long long;


int memo[1003][1003];

int maze[1003][1003];
int findways(int i,int j,int m,int n){
    if(maze[1][1]=='X')return 0;
    if(i==m && j==n)return 1;
    if(maze[i][j]=='X')return 0;
    if(maze[m][n]=='X')return 0;
    if(i>m ||i<1 || j<1|| j>n)return 0;
    if(memo[i][j]!=-1)return memo[i][j];
    
    int x1=findways(i+1,j,m,n);
    int x2=findways(i,j+1,m,n);
    memo[i][j]=((x1%1000000007)+(x2%1000000007))%1000000007;
    return memo[i][j];
}
int main(){ 

    int m;int n;
    cin>>m;cin>>n;
    memset(maze,0,sizeof(maze));
    memset(memo,-1,sizeof(memo));
    int k;cin>>k;
    int x;int y;
    for(int i = 0; i < k; i++)
    {
        cin>>x;
        cin>>y;
        maze[x][y]='X';
    }
    cout<<findways(1,1,m,n);
    return 0;
}

