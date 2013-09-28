#include <cmath>
#include <cstdio>
#include <queue>
#include <utility>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector< vector<pair<int,int> > > cost(50002);
vector<bool> visited(50002,false),reachable(50002,false);
vector<int> minFare(50002,-1);

class compare
{
	public:
		bool operator() (const pair<int,int>& a,const pair<int,int>& b)
		{
			return a.second > b.second;
		}
};

int dijikstra(int n)
{
	priority_queue< pair<int,int>,vector<pair<int,int> >,compare > q;
	q.push(make_pair(1,1));
	int minFare = -1;

	while( q.size() > 0 )
	{
		pair<int,int> node = q.top();
		q.pop();
		visited[node.first] = true;
//		cout<<"Node "<<node.first<<" Cost : "<<node.second<<endl;
		if( node.first == n && (minFare == -1 || minFare > node.second) )
		{
			minFare = node.second;
			return minFare;
		}

		for(int i=0;i<cost[node.first].size();i++)
		{
			int adj = cost[node.first][i].first;
			int acost = cost[node.first][i].second;
			if( visited[adj] == false )
				q.push(make_pair(adj,std::max(node.second,acost)));
		}
	}
}


int main() {
    
    std::ios_base::sync_with_stdio(false);
    int n,e,u,v,c,minFare = -1;
    cin>>n>>e;
    for(int i=0;i<e;i++)
    {
        cin>>u>>v>>c;
        cost[u].push_back(make_pair(v,c));
	cost[v].push_back(make_pair(u,c));
    }
    minFare = dijikstra(n);
    if(visited[n])
        cout<<minFare<<endl;
    else
        cout<<"NO PATH EXISTS\n";
    
    return 0;
}

