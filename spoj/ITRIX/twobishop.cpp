#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	int x,y,x1,y1,t,flag;
	char c;
	scanf("%d",&t);
	while(t--)
	{
		flag=0;
		for(int i=0;i<=7;i++)
		{
			for(int j=0;j<=7;j++)
			{
				cin>>c;
				if(c != '.')
				{
					if(flag == 0)
					{
						x=i;
						y=j;
						flag=1;
					}
					else
					{
						x1=i;
						y1=j;
					}
				}
			}
		}
		int temp=x1-x;
		int temp1=y1-y;
		if(temp < 0)
			temp=-temp;
		if(temp1<0)
			temp1=-temp1;
		if(temp == temp1)
			printf("Yes\n");
		else
			printf("No\n");
	}
}

