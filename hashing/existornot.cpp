

//myversion
/*
#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    int t;
    cin>>t;
    int n;
    cin>>n;
    
    while(t!=0){
        unordered_map<int,int> m;
        int ar[n];
        for(int i=0;i<n;i++){
            cin>>ar[i];
            m[ar[i]]=1;
        }
        int q;
        cin>>q;
        int d;
        for(int i=0;i<q;i++){
            cin>>d;
            if(m[d]){
                cout<<"Yes"<<endl;
            }
            else
            {
                cout<<"No"<<endl;
            }
            
        }
        t--;
    }


    return 0;
}
*/
//correct

#include<iostream>
#include<unordered_map>
#define ll long long int

using namespace std;

int main() {
  
  int t;
  cin>>t;
  while(t--)
  {
    unordered_map<ll, ll> m;
    int l;
    cin>>l;
    for(int i=0; i<l; i++)
    {
      ll no;
      cin>>no;
      m[no]=i;
    }
    int q;
    cin>>q;
    if(q>=0){
    while(q--)
    {
      ll no_to_search;
      cin>>no_to_search;
      if(m[no_to_search])
      {
        cout<<"Yes"<<endl;
      }
      else
      {
        cout<<"No"<<endl;
      }
    }
    }
  }
	return 0;
}