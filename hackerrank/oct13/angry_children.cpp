#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    
    vector<int> ar;
    int n,k,x,lower=( (int)(1e9) + 1);
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        ar.push_back(x);
    }
    sort(ar.begin(),ar.end());
    
    for(int i=0;(i+k-1)<n;i++)
    {
        int min = ar[i];
        int max = ar[i+k-1];
        
        lower = ( (max-min) < lower ? (max-min) : lower);
    }
    cout<<lower<<endl;
        
    return 0;
}

