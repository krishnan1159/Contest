#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int b[23],n,i,l,min=0,count=0,j,a[23];
		memset(a,-1,sizeof(a));
		scanf("%d%d",&n,&l);
		for(i=0;i<l;i++)
		{
			scanf("%d",&b[i]);
			a[b[i]]=1;
		}
		//Finding for all in the l array//
		a[0]=0;
		sort(b,b+l);
		for(i=1;i<=n;i++)
		{
			//Less than the minimum//
			int temp=i%22;
			if(temp == 0)
				temp=22;
			if(i < b[0])
				a[i]=0;
			else
			{
				for(j=0;j<l;j++)
				{
					int temp1=(i-b[j])%22;
					if(temp1 == 0)
						temp1=22;
					if( a[temp1] == 0)
					{
						count++;
						a[temp]=1;
						break;
					}
				a[temp]=0;
				}
			}
		}
		printf("%d\n",count);
	}
}
