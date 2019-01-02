#include<iostream>
#include<unordered_map>
#include<list>
#include<cstring>
using namespace std;

class graph
{
	int V;
	unordered_map<string,list<string> > m;

	public:
		graph(int v){
			V=v;
		}
		void addedge(string src,string dest, bool bidir=true){
		m[src].push_back(dest);
			if(bidir){
				m[dest].push_back(src);
			}
		}

		void print(){
			for(auto p:m){
				string src=p.first;
				auto cities=p.second;
				cout<<src<<"-->";
				for(auto city:cities){
					cout<<"("<<city<<",)";

				}
				cout<<endl;
			}

		}
		void dfshelper(string node,unordered_map<string,bool> &visited){
			cout<<node<<" ";
			visited[node]=true;

			for(auto child:m[node]){
				if(!visited[child]){
					dfshelper(child,visited);
				}
			}
		}

		void dfs(string src){
			//visit the current node
			//mark it as visited
			//explore any unvisited child of that node repeat
			unordered_map<string,bool> visited;
			dfshelper(src,visited);


		}
};

int main(){
	string s;
	graph g(5);
	g.addedge("Delhi","Lucknow");
	g.addedge("Delhi","Amritsar");
	g.addedge("Bhopal","Delhi");
	g.addedge("Delhi","Jaipur");
	g.addedge("Bhopal","Jaipur");
	g.print();
	cout<<endl;
	cin>>s;
	g.dfs(s);

}