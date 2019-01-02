#include<iostream>
//find number of people in a room such that p of 2 people having same bday is n%
using namespace std;
int main(){


	float prob;
	cin>>prob;
	float nprob;

	nprob=1-prob;
	int cnt=0;
	float num=1.0;
	float people=365.0;
	while(num>=nprob){

		num=num*(people/365);
		people--;
		cnt++;
	}
	cout<<cnt;
	return 0;
}