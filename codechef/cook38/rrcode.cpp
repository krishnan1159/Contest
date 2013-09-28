#include<iostream>
#include<string>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int n,k,ans,resAnd,resOr,resXor,x;
		string s;
		cin>>n>>k>>ans;
		cin>>x;
		resAnd = resOr = resXor = x;
		for(int i=1;i<n;i++)
		{
			cin>>x;
			resAnd &= x;
			resOr |= x;
			resXor ^= x;
		}
		cin>>s;
		if( s == "XOR" )
		{
			if( k%2 == 1 )
				cout<<(ans^resXor)<<endl;
			else
				cout<<ans<<endl;
		}
		else if( s == "AND" )
			cout<<(ans&resAnd)<<endl;
		else
			cout<<(ans|resOr)<<endl;
	}
}
