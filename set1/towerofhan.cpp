#include<iostream>
using namespace std;

void towerofhan(int n,char src,char hel,char des){

    if(n==0){
        return;
    }
    towerofhan(n-1,src,des,hel);
    cout<<"Move "<<n<<" from "<<src<<" to "<<des<<endl;
    towerofhan(n-1,hel,src,des);
}

int main(){

    towerofhan(4,'A','B','C');
    return 0;
}