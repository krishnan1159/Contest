#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

long long int comb[65][34];
long long int maxComb[65];

void compute()
{
	memset(comb,0,sizeof(comb));
	int i,j;
	comb[0][0]=1;
	comb[1][0] = comb[1][1] = 1;

	for(i=2;i<65;i++)
	{
		comb[i][0] = 1;
		for(j=1;(j<i && j<33);j++)
			comb[i][j] = comb[i-1][j] + comb[i-1][j-1];
		if( j<33 )
			comb[i][i] = 1;
		maxComb[i] = comb[i][i/2];
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	compute();
	int t;
	cin>>t;
	while(t--)
	{
		long long int n;
		cin>>n;	
		cout<<(lower_bound(maxComb,maxComb+64,n)-maxComb)<<endl;		
	}
}
