#include<stdio.h>
#include<vector>
#include<iostream>
#include<queue>
using namespace std;

#define fori(a,b) for(i = a; i <= b; i++)
#define forj(a,b) for(j = a; j <= b; j++)
#define scani(a) scanf("%d",&a);

#define INF 1000000000

struct ncost
{
	int node;
	int cost;
};

struct compare
{
	bool operator()(const struct ncost& a, const struct ncost& b)
	{
		return a.cost > b.cost;
	}
};
int main()
{
	int t,i,j,c;
	char src, dest, x, y;
	int mat[15][15] = {0};
	int stop[15];
	scani(t)
	while(t--)
	{
		fori(0,14)
			scani(stop[i])
		fori(0,25)
		{
			cin>>x;
			cin>>y;
			scani(c)
			mat[x-65][y-65] = mat[y-65][x-65] = c;
		}
	/*	printf("after 26");
		fori(0,14)
		{
			forj(0,14)
				printf("%d ",mat[i][j]);
			printf("\n");
		}*/
		fori(0,14)
			forj(0,14)
				if(mat[i][j] != 0)
					mat[i][j] += stop[j];
	/*	printf("\n\n");
		fori(0,14)
		{
			forj(0,14)
				printf("%d ",mat[i][j]);
			printf("\n");
		}*/

		cin>>src;
		cin>>dest;
		//scanf("%c",&src);
		//scanf("%c",&dest);
		
		struct ncost start;
		start.node = src - 65;
		start.cost = stop[start.node];
		
		priority_queue<struct ncost, vector<struct ncost>, compare> q;
		q.push(start);
		
		bool visited[15];
		fori(0,14)
			visited[i] = false;
		visited[src-65] = true;
		struct ncost p;
		
		while(!q.empty())
		{
			p = q.top();
			q.pop();
			visited[p.node] = true;
		//	printf("popped : %c %d\n",p.node+65, p.cost);
			if(p.node == dest-65)
				break;
			fori(0,14)
			{
				if(visited[i] == false && mat[p.node][i] != 0)
				{
					struct ncost n;
					n.node = i;
					n.cost = p.cost + mat[p.node][i];
					//visited[i] = true;
					q.push(n);
			//		printf("pop : %c %d\n",q.top().node+65, q.top().cost);
					
				}
			}
		}
		printf("%d\n",p.cost - stop[p.node]);		
	}
	return 0;
}
