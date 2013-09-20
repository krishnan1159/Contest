#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		long long int sum = 0LL,x=0,max=0;
		scanf("%d%d",&n,&k);
		for(int i=0;i<n;i++)
		{
			scanf("%lld",&x);
			sum+=x;
			if( x > max )
				max = x;
		}
		sum = sum/k + (sum%k == 0 ? 0 : 1);

		cout<<std::max(sum,max)<<endl;
	}
}
