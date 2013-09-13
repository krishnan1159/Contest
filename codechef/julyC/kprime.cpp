#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
using namespace std;
vector<int> v;
vector<vector<int> > inp;
vector<bool> flag(320);
int countPrimes(int num)
{
	vector<int>::iterator it=v.begin();
	int count=0,flag=0;
	for(;it!=v.end() && (*it) <= num;it++)
		if(num % (*it) == 0)
			count++;
	return count;
}
void intialize()
{
	//Generate primes upto 317 sqrt(100000)
	int i,j,l;
	v.push_back(2);
	for(i=3;i<318;i+=2)
	{
		if(flag[i] == 0)
		{
			v.push_back(i);
			for(j=i*i,l=(i<<1);j<318;j+=l)
				flag[j]=1;
		}
	}
	//Generate K- Primes from 2 - 5
	inp[2]=1;
	inp[3]=1;
	for(i=4;i<100001;i++)
	{
		if(countPrimes(i);
}
int main()
{
		int t;
		intialize();
		scanf("%d",&t);
		while(t--)
		{
			int a,b,k,count=0;
			scanf("%d%d%d",&a,&b,&k);
			for(int i=a;i<=b;i++)
				if(inp[i] == k)
					count++;
			printf("%d\n",count);	
		}
}
