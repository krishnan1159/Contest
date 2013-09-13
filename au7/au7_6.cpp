#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
using namespace std;
set<int> a,final1;
int n;
set<int>& product(set<int>& s,set<int>& s1)
{
	final1.clear();
	set<int>::iterator it=s.begin();
	set<int>::iterator it1;
	if(s.empty())
	{
		for(it1=s1.begin();it1!=s1.end();it1++)
			final1.insert(*it);
		return final1;
	}
	for(;it!=s.end();it++)
		for(it1=s1.begin();it1!=s1.end();it1++)
			final1.insert( (*it)*(*it1));
	return final1;
}

void findAns(int k)
{
	printf("Called");
	set<int> final;
	while(k)
	{
		if( (k&1) == 1)
			final=product(final,a);
		a=product(a,a);
	}
	set<int>::iterator it;
	for(it=final.begin();it!=final.end();it++)
		printf("%d ",*it);
	printf("\n");
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		a.clear();
		long long int k;
		int n,m,i,j;
		scanf("%lld",&k);
		scanf("%d%d",&m,&n);
		cout<<n<<endl;
		for(i=1;i<=n;i++)
		{
			cout<<"HH";
			scanf("%d",&j);
			a.insert(j);
			cout<<j<<endl;
		}
		printf("Over");
		findAns(k);
	}
}
