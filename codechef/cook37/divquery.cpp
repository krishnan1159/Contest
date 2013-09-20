#include<iostream>
#include<cstdio>
#include<vector>
#include<utility>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	int n,q,x,l,r,k,i,maxk=0,sqr,j,y;
	cin>>n>>q;
	vector<int> inp(n+1);
	vector<vector<int> > ans(100001);

	for(i=0;i<n;i++)
	{
		scanf("%d",&inp[i]);
		sqr = sqrt(inp[i]);
		for(j=1;j<=sqr;j++)
			if( inp[i] % j == 0 )
			{
				if( j != (inp[i]/j) )
					ans[j].push_back(i);
				ans[ inp[i]/j ].push_back(i);
			}
	}

	for(i=0;i<q;i++)
	{
		scanf("%d%d%d",&l,&r,&k);
		l--;
		r--;
		x = ( std::upper_bound(ans[k].begin(),ans[k].end(),l-1) - ans[k].begin());
		y = ( std::lower_bound(ans[k].begin(),ans[k].end(),r+1) - ans[k].begin());
		cout<<y-x<<endl;
	}

}

