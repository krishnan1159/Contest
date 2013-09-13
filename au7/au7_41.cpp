#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int length[300002];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k,i,j,count=1,visited=2,finalcount=0;
		memset(length,-1,sizeof length);
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;i++)
		{
			char cow[20];
			scanf("%s",cow);
			length[i]=strlen(cow);
		}
		for(i=1;i<=n;i++,count=1)
		{
			for(j=visited;j<=n && j<=(i+k);j++)
			{
				if(length[i] == length[j])
					count++;
			}
			visited=i+visited+1;
			finalcount+=(count*(count-1))/2;
		}
		printf("%d\n",finalcount);
	}

}
