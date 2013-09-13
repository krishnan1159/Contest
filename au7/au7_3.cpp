#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int m,n,r,c,dot=0,i,j,k,o,idx,l,idxx;
		char print[]={'X','.'};
		scanf("%d%d%d%d",&m,&n,&r,&c);
		idx=0;
		for(i=1;i<=m;i++,idx^=1)
		{
				for(k=1;k<=r;k++)
				{
					idxx=idx;
					for(o=1;o<=n;o++,idxx^=1)
					{
						for(l=1;l<=c;l++)
						{
							printf("%c",print[idxx]);
						}
					}
					printf("\n");
				}
		}
	}

}

