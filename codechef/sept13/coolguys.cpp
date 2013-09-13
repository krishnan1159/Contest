#include<iostream>
using namespace std;
long long int gcd(long long int a,long long int b)
{
	if( b == 0 )
		return a;

	return gcd(b,a%b);
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		long long int n,cnt = 0,divisors,b,sq;
		cin>>n;
		cnt = n;
		sq = n*n;
		for(b=2;b<=(n>>1LL);b++)
		{
			divisors = n/b;
			cnt+= divisors;
		}

		cnt+=(n-(n>>1LL));
		if( n == 1)
			cnt--;

		int gc = gcd(sq,cnt);
		cout<<(cnt/gc)<<"/"<<(sq/gc)<<endl;
	}
}
