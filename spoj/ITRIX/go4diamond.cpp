#include<iostream>
#include<cstdio>
using namespace std;
#define max(a,b) a>b?a:b

int map[201][201];
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		int n,half,i,j,k;
		scanf("%d",&n);
		half=(n>>1);
		for(i=0;i<=half;i++)
		{
			for(j=0;j<=i;j++)
			{
				if(i == 0)
				{
					scanf("%d",&map[i][j]);
				}
				else
				{
					scanf("%d",&map[i][j]);
					if(j == 0)
						map[i][j]+=map[i-1][j];
					else if(j == i)
						map[i][j]+=map[i-1][i-1];
					else
						map[i][j]+=(max(map[i-1][j-1],map[i-1][j]));
				}
			}
			/*cout<<"output\n";
			for(j=0;j<=i;j++)
				cout<<map[i][j]<<" ";
			cout<<endl;*/
				
		}
	
		for(i=0;i<half;i++)
		{
			k=half+i+1;
			for(j=0;j<(half-i);j++)
			{
				scanf("%d",&map[k][j]);
				map[k][j]+=(max(map[k-1][j],map[k-1][j+1]));
			}
			/*cout<<"output\n";
			for(j=0;j<(half-i);j++)
				cout<<map[k][j]<<" ";
			cout<<endl;*/
		}
		printf("%d\n",map[n-1][0]);
	}
}
