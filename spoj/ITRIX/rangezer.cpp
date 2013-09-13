#include<iostream>
#include<cstdio>
using namespace std;
int findCount(int n)
{
	int tempn=0,nn=n,i=1,j,zerocount=1,flag=0;
	while(n>9)
	{
		int temp=(n/10);	
		if(flag == 0)
		{
			flag=1;
			zerocount+=(temp*i);
		}
		else
		{
			if(n%10 == 0)
			{
				temp=(temp-1)*i+tempn+1;
			}
			else
				temp=temp*i;
			zerocount+=temp;
		}
		tempn=(nn%(i*10));
		n/=10;
		i*=10;
	}
	return zerocount;
}

int main()
{
	int t,ca=1;
	scanf("%d",&t);
	while(t--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		//printf("\nCount : %d\n",findCount(a-1));
		//printf("Count : %d\n",findCount(b));
		printf("Case %d: %d\n",ca++,findCount(b)-findCount(a-1));
	}
}
