#include <iostream>
using namespace std;

void permute(char *a,int n,int pos)
{
    if(a[pos]=='\0'){
        cout<<a<<endl;
        return;
    }
    for(int j=pos;j<n;j++){
        swap(a[j],a[pos]);
        permute(a,n,pos+1);
        swap(a[j],a[pos]);
    }
}
int main() {
  char a[10]="abc";
  permute(a,3,0);

  return 0;
}
