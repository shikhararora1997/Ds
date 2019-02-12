#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    int ar[n];
    unordered_map<int,int> m;
    for(int i=0;i<n;i++){
        cin>>ar[i];
        m.insert(make_pair(ar[i],i));
    }
    int cnt=0;
    int temp=n;
    while(k!=0 && cnt<n){
        if(ar[cnt]!=temp){
          int pos=m[temp];
          m[ar[cnt]]=pos;
          swap(ar[cnt],ar[m[temp]]);
          k--;
        }
        cnt++;
        temp--;
      
    }
    for(int i=0;i<n;i++){
        cout<<ar[i]<<" ";
    }
    return 0;
}