#include<iostream>
#include<queue>
#include<vector>
#include<utility>
using namespace std;


typedef pair<int, pair<int,int> > op;
vector<int> mergek(vector<vector<int> > arr){

	priority_queue<op, vector<op>,greater<op> > pq;
	vector<int> output;
	
	for(int i=0;i<arr.size();i++){
		pq.push(make_pair(arr[i][0],make_pair(i,0)));
	}
	while(!pq.empty()){
		op cur=pq.top();
		pq.pop();

		int i=cur.second.first;
		int j=cur.second.second;

		output.push_back(cur.first);

		    if (j + 1 < arr[i].size()) 
            pq.push(make_pair(arr[i][j + 1], make_pair(i, j + 1 ) )); 
    } 
  
    return output; 

	


}
int main(){
	vector<vector<int> > arr;
	int k;
	int n;
	cin>>k;
	cin>>n;
	for(int i=0;i<k;i++){
		
		vector<int> ar;
		
		int x;
		for(int i=0;i<n;i++){
			cin>>x;
			ar.push_back(x);
		}
		arr.push_back(ar);
	}
	vector<int> output=mergek(arr);
  	for(int i=0;i<output.size();i++)
  		cout<<output[i]<<" ";


	return 0;
}