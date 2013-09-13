#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int a[100002],pos[100002];
vector< pair<int,int> > v;
queue<int> forward,backward;
vector< pair<int,int> >::iterator it;
vector< pair<int,int> >::reverse_iterator rit;
int main()
{
	int n,k,i,j,left,right,x,forw,back;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		v.push_back(make_pair(i,x));
	}
	//Calculation Forward and Backward
	it=v.begin();
	rit=v.rbegin();
	forw=(*it).second;
	back=(*rit).second;
	it++;
	rit++;
	while(it != v.end())
	{
		if( (*it).second > forw )
		{
			forw=(*it).second;
			forward.push( (*it).first);
		}
		if( (*rit).second > back )
		{
			back=(*rit).second;
			backward.push( (*rit).first);
		}
		it++;
		rit++;
	}
	//Sorting the vector
	sort(v.begin(),v.end());
	//Calcuating the vismin value
	left=1;
	right=n;
	for(it=v.begin();it!=v.end();it++)
	{
		pair<int,int> temp=*it;
		if(temp.second == left)
		{
			left=forward.front();
			forward.pop();
		}
		else if(temp.second == right)
			right--;
		
	}
}
