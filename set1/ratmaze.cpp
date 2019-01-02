#include<iostream>
using namespace std;

int count=0;
bool ratInMaze(char maze[10][10],int path[][10],int i,int j,int m,int n){

    //base case
    if(i==m && j==n){
        count++;
        path[i][j]=1;
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                cout<<path[i][j];
            }
            cout<<endl;
        }
            path[i][j]=0;
            cout<<endl;
            return true;
    }
    if(i>m || j>n){
        return false;
    }
    if(maze[i][j]=='X'){
        return false;
    }

    path[i][j]=1;

    bool rightpath=ratInMaze(maze,path,i,j+1,m,n);
    bool leftpath=ratInMaze(maze,path,i+1,j,m,n);

    path[i][j]=0;

	
    if(rightpath || leftpath){
        return true;
    }
    else
        return false;
}
int main(){

	char maze[10][10] = {
					   "000X",
					   "0X00",
					   "00X0",
					   "000X",
					   "0X00"
					  };
	int path[10][10]={0};
	int m,n;
	m = 5,n=4;

	ratInMaze(maze,path,0,0,m-1,n-1);
	cout<<endl;
	cout<<count;
	return 0;
}