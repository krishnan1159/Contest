#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
using namespace std;
vector<vector<int> > inp(100002);
vector<int> minCost;
int cost[100002],visited[100002];
//DFS traversal of a graph
int dfs(int node,int& min)
{
	vector<int>::iterator it=inp[node].begin();
	visited[node]=1;
	if( (min < 0 && cost[node] >= 0) || (min >= 0 && cost[node]>=0 && cost[node] < min) )
		min=cost[node];
	while( it != inp[node].end() )
	{
		if(visited[*it] == 0)
			dfs(*it,min);
		it++;
	}
	return min;
}
int main()
{
	int n,m,i,j,x,y,min=10001,flag=0,numComponents=0;
	long long int sum=0LL;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		inp[x].push_back(y);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d",&cost[i]);
	}
	// 'inp' is a input graph. 'cost' is a cost matrix.
	// 'minCost' - minimum cost of each bipartite graph

	memset(visited,0,sizeof visited);
	//Check each node in the graph whether it is visited
	for(i=1;i<=n;i++)
		if(visited[i] == 0)
		{
			numComponents++;
			x=dfs(i,cost[i]);
			printf("Check %d \n",x);
			if(x < 0)
				flag=1;
			else
			{
				if(x < min)
					min=x;
				sum+=x;
			}
		}
//	cout<<"Min "<<min<<"Sum "<<sum<<"NUm "<<numComponents<<endl;

	if(numComponents == 1)
		printf("0\n");
	else
		if(flag == 1)
			printf("-1\n");
		else
			printf("%lld\n",sum+((long long int)(numComponents-2))*((long long int)min));
}
