#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool compare(const int& a,const int& b)
{
	return a > b;
}

int main()
{
	int n,x;
	cin>>n;
	vector<int> ar;
	
	for(i=0;i<n;i++)
	{
		int x;
		cin>>x;
		if( x < 0 )
			ar.push_back(-x);
	}

	cin>>x;

	std::sort(ar.begin(),ar.end(),compare);
	if(ar.size() == 0)
	{
		cout<<"0"<<endl;
		return;
	}

	long long int sum = std::accumulate(ar.begin(),ar.end());

	if( x >= ar.size() )
	{
		cout<<sum<<endl
		return;
	}
	
	int left = x;
	int right = ar.size() - x;

}
