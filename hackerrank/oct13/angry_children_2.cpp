#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    
    std::ios_base::sync_with_stdio(false);
    
    int n,k,x,i,minAns = 0,ans=0,addFactor = 0,subFactor = 0;
    vector<int> packets;
    cin>>n>>k;
    
    for(i=0;i<n;i++)
    {
        cin>>x;
        packets.push_back(x);
    }
    
    std::sort(packets.begin(),packets.end(),greater<int>());
    /* Now the Values in packets are sorted in decreasing order */
    
    vector<int> sum(n+2,0);
    for(i=1;i<n;i++)
        sum[i] = sum[i-1] + packets[i-1];
    
    for(i=1;i<k;i++)
    {
        addFactor = sum[i] - i*packets[i];
        ans += addFactor;
    }
    minAns = ans;
    
    for(i=k;i<n;i++)
    {
        subFactor = packets[i-k] * (k-1) - (sum[i]-sum[i-k+1]);
        addFactor = (sum[i] - sum[i-k+1]) - packets[i]*(k-1);

	cout<<addFactor<<" "<<subFactor<<endl;
       
        ans = ans + addFactor - subFactor;
        
        minAns = (ans < minAns) ? ans : minAns;
    }
    
    return 0;
}

