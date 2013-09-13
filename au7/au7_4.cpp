#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int length[300002],visited[300002];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k,i,j,count=0;
		memset(length,-1,sizeof length);
		memset(visited,-1,sizeof visited);
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;i++)
		{
			char cow[20];
			scanf("%s",cow);
			length[i]=strlen(cow);
		}
		for(i=1;i<=n;i++)
			for(j=i+1;j<=n && j<=(i+k);j++)
				if(length[i] == length[j])
					count++;
		printf("%d\n",count);
	}

}
