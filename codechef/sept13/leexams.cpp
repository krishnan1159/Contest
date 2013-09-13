#include<iostream>
#include<vector>
#include<utility>
using namespace std;

void calcProb(vector< vector<int> >& inp,vector<bool>& flag,int i,int n,float tp,float& ans)
{
	if( i == n )
	{
//		cout<<"prob"<<tp<<endl;
		ans+=tp;
		return;
	}
	int j=1;
	if( flag[ inp[i][j] ] == false )
	{
		flag[ inp[i][j] ] = true;
		float temp = (float)inp[i][0]/100.0;
//		cout<<"p"<<temp<<endl;

		calcProb(inp,flag,i+1,n,tp*temp,ans);

		flag[ inp[i][j] ] = false;
	}
	j=2;
	if( flag[ inp[i][j] ] == false )
	{
		flag[ inp[i][j] ] = true;
		float temp = (float)(100-inp[i][0])/100.0;

		calcProb(inp,flag,i+1,n,tp*temp,ans);

		flag[ inp[i][j] ] = false;
	}
	return;

}

int main()
{
	std::ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int n,i;
		float max=0.0000000000000000f;
		cin>>n;
		vector< vector<int> >inp(n+1,vector<int>(3));
		vector<bool>flag(18,false);

		for(i=0;i<n;i++)
			cin>>inp[i][0]>>inp[i][1]>>inp[i][2];

		calcProb(inp,flag,0,n,1.0,max);

		cout<<max<<endl;
	}
}
