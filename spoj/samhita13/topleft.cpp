#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int matrix[16][16],val,i,j,r,c,a[16][16],k,left,top,flag=0,rmid,cmid,min;
		scanf("%d%d",&r,&c);
		for(i=0;i<r;i++)
			for(j=0;j<c;j++)
				scanf("%d",&matrix[i][j]);
		scanf("%d",&val);
		k=1;
		rmid=r/2+r%2;
		cmid=c/2+c%2;
		//Sets the value for row and column//
		for(i=0;i<r;i++)
		{
			if(i < rmid)
				top=i;
			else
				top=r-i;
			for(j=0;j<c;j++)
			{
				if(j < cmid)
					left=j;
				else
					left=c-j;
				a[i][j]=top+left;
				//cout<<a[i][j]<<" ";
			}
			//cout<<endl;
		}
		for(i=0;i<r;i++)
			for(j=0;j<c;j++)
				if(matrix[i][j] == val)
				{
					if(flag == 0)
					{
						min=a[i][j];
						flag=1;
					}
					min=(min > a[i][j])?a[i][j]:min;
				}
		if(flag==0)
			cout<<-1<<endl;
		else
			cout<<min<<endl;
	}
}
