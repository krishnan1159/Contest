#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    
    int t;
    cin>>t;
    while(t--)
    {
        long long int n,k,quot=0LL,rem=0LL,i=0LL,top=0LL,bottom=0LL,cnt=0LL;
        cin>>n>>k;
        
        quot = n/k;
        rem = n%k;
        
        cnt = ( quot*(quot-1) )/2;
        i = 1;
        while( i <= (k>>1) )
        {
           if(i <= rem) 
               top = quot+1;
            else
                top = quot;
            if((k-i) <= (rem))
                bottom = quot+1;
            else
                bottom = quot;
            
            if(i !=(k-i))
                cnt += (bottom*(bottom+1))/2;
            
            cnt += (top*(top-1))/2;
            
            i++;
        }
        cout<<cnt<<endl;
    }
    
}

