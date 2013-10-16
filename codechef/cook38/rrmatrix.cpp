#include<iostream>
using namespace std;

int gcd(int a,int b)
{
	if(b == 0)
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
		int m,n,g;
		cin>>m>>n;
		if( m < n )
			std::swap(m,n);
		g = gcd(m-1,n-1);
		if( m == 1 || n == 1 )
			cout<<std::max(m,n)<<endl;
		else
			cout<<g+1<<endl;
	}
}
