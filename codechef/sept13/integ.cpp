#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;

bool compare(const int& a,const int& b)
{
	return a > b;
}

int main()
{
	int n,x,i;
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

	if(ar.size() == 0 || x == 0)
	{
		cout<<"0"<<endl;
		return 0;
	}
	std::sort(ar.begin(),ar.end(),compare);

	long long int sum = 0;
	i = 0;
	while( x >= 1 && i<ar.size() )
	{
		sum += ar[i];
		x--;
		i++;
	}

	cout<<sum<<endl;
	return 0;

}
