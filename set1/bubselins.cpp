#include <iostream>
using namespace std;

void bubble(int *ar,int s){

    for(int i=0;i<s-1;i++){
        for(int j=0;j<s-i-1;j++){
            if(ar[j]>ar[j+1]){
                swap(ar[j],ar[j+1]);
            }
        }
    }
}
void selection(int *ar,int s){

    
    for(int i=0;i<s-1;i++){
        int small=i;
        for(int j=i+1;j<s;j++){
            if(ar[small]>ar[j]){
                small=j;
            }
            swap(ar[i],ar[small]);
        }
    }
}
void insertion(int *ar,int s){

    for(int i=1;i<s;i++){
        int key=ar[i];
        int j=i-1;
        while(ar[j]>key && j>=0){
            ar[j+1]=ar[j];
            j=j-1;
        }
        ar[j+1]=key;
    }

}
int main() {
    int a[5]={2,3,1,4,6};
    for(int i=0;i<5;i++){
        cout<<a[i];
    }
    cout<<endl;
    insertion(a,5);
     for(int i=0;i<5;i++){
        cout<<a[i];
    }
}
