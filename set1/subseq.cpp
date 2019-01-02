#include<iostream>
#include<set>
#include<cstring>
using namespace std;


void subsequences(char *in,char *out,int i,int j){
	//Base Case
	if(in[i]=='\0'){
		out[j] = '\0';
		cout<<out<<endl;
		return;
	}
	//Rec Case
	out[j] = in[i];
	subsequences(in,out,i+1,j+1);
	subsequences(in,out,i+1,j);
    

}

int main(){

	char a[100];
	cin>>a;

	char out[100];
    for(int i=0;a[i]!='\0';i++){
        
    }	subsequences(a,out,0,0);
    
	return 0;
}