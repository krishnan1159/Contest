#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

int dfs(int chef,int amt,vector<int>& p,vector<int>& health,vector<int>& al,vector< vector<int> >& inf)
{
	if( al[chef] == 0 )
	{
		health[chef] -= amt;

	        if( health[chef] > 0 )
        	        return 1;

		p[chef] = 0;
		return 0;
	}

	int i,cnt=0;
	amt += p[chef];
	for(i=0;i<inf[chef].size();i++) /* counting how many inferiors are alive */
		cnt += dfs(inf[chef][i],amt,p,health,al,inf);

	amt -= p[chef];
	al[chef] = cnt; /* Updating the inferior nodes */
	p[chef] = 0;
	health[chef] -= amt; /* Updating the health */

	if( health[chef] > 0 )
		return cnt+1;

	return cnt;
}

int computeInfe(int node,vector<int>& alive,vector< vector<int> >& inf)
{
	int cnt = 0,i;
	
	for(i=0;i<inf[node].size();i++)
	{
		int idx = inf[node][i];
		cnt+=computeInfe(idx,alive,inf);
	}
	alive[node] = cnt;
	return cnt+1;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	int n,q,i,type,x,y,alive = 0,start = 1000000;
	cin>>n;

	vector<int> health(n+2),poison(n+2,0),al(n+2,0);
	vector< vector<int> > inf(n+2);
	
	for(i=1;i<=n;i++)
	{
		cin>>health[i]>>x;
		inf[x].push_back(i);
	}
	computeInfe(0,al,inf);
/*	for(i=0;i<=n;i++)
		cout<<al[i]<<" ";
	cout<<endl;*/

	cin>>q;
	while(q--)
	{
		cin>>type;
		if( type == 1 )
		{
			cin>>x>>y;
			poison[x]+=y;
		}
		else
		{
			cin>>start;
			dfs(start,0,poison,health,al,inf);
			cout<<al[start]<<"\n";
		}
	}
}
