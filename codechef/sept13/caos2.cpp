#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

int l[501][501],top[501][501],bot[501][501];
int r[502][502];
char inp[502][502];
vector<int> primes;
vector<bool> flag(504);

void precompute()
{
	int i,j,k;
	primes.push_back(2);
	for(i=3;i<=500;i+=2)
	{
		if( flag[i] == false )
		{
			primes.push_back(i);
			for(j=i*i,k=(i<<1);j<=500;j+=k)
				flag[j] = true;	
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	precompute();

	int t;
	cin>>t;
	while(t--)
	{
		memset(l,0,sizeof(l));
		memset(r,0,sizeof r);
		memset(top,0,sizeof top);
		memset(bot,0,sizeof bot);
		memset(inp,0,sizeof inp);

		int row,c,i,j,cnt=0,n;
		cin>>row>>c;

		for(i=0;i<row;i++)
			cin>>inp[i];

		for(i=0,n=c;i<row;i++)
		{
			l[i][0] = 0;
			r[i][n-1] = 0;
			for(j=1;j<c;j++)
			{
				if( inp[i][j] == '^' )
					l[i][j] = l[i][j-1] + ( (inp[i][j-1] == '^') ? 1 : 0);
				else
					l[i][j] = 0;

				if( inp[i][n-1-j] == '^' )
					r[i][n-1-j] = r[i][n-j] + ( (inp[i][n-j] == '^') ? 1 : 0);
				else
					r[i][n-1-j] = 0;
			}
		}

		for(i=0;i<c;i++)
		{
			top[0][i] = 0;
			bot[row-1][i] = 0;
			for(j=1;j<row;j++)
			{
				if( inp[j][i] == '^' )
					top[j][i] = top[j-1][i] + ( (inp[j-1][i] == '^') ? 1 : 0 );
				else
					top[j][i] = 0;
				
				if( inp[row-1-j][i] == '^' )
					bot[row-1-j][i] = bot[row-j][i] + ( (inp[row-j][i] == '^' ) ? 1 : 0 );
				else
					bot[row-1-j][i] = 0;
			}
		}
//		cout<<l[2][3]<<" "<<r[2][3]<<" "<<top[2][3]<<" "<<bot[2][3]<<endl;

		for(i = 0;i<row;i++)
			for(j=0;j<c;j++)
				if( inp[i][j] == '^' )
				{
					int m = std::min( std::min(l[i][j],r[i][j]),std::min(top[i][j],bot[i][j]) );
					if( m > 1 )
						cnt += ( std::lower_bound(primes.begin(),primes.end(),m+1) - primes.begin() );
				}

		cout<<cnt<<endl;
	}
}
