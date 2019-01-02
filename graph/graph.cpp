#include<iostream>
#include<unordered_map>
#include<list>
#include<cstring>
using namespace std;

class graph
{
	int V;
	unordered_map<string,list<pair<string,int> > > m;

	public:
		graph(int v){
			V=v;
		}
		void addedge(string src,string dest,int wt, bool bidir=true){
		m[src].push_back(make_pair(dest,wt));
			if(bidir){
				m[dest].push_back(make_pair(src,wt));
			}
		}

		void print(){
			for(auto p:m){
				string src=p.first;
				auto cities=p.second;
				cout<<src<<"-->";
				for(auto city:cities){
					cout<<"("<<city.first<<","<<city.second<<")";

				}
				cout<<endl;
			}

		}
};

int main(){
	
	graph g(5);
	g.addedge("Delhi","Lucknow",3);
	g.addedge("Delhi","Amritsar",1);
	g.addedge("Bhopal","Delhi",6);
	g.addedge("Delhi","Jaipur",2);
	g.addedge("Bhopal","Jaipur",4);
	g.print();

}