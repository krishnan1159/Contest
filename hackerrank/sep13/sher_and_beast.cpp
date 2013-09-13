#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int lenThree[100002];

void precompute()
{
    int i;
    lenThree[0] = lenThree[1] = lenThree[2] = lenThree[4] = lenThree[7] = -1;
    lenThree[3] = 0;
    lenThree[5] = 5;
    lenThree[6] = 0;
    
    for(i=8;i<=100000;i++)
    {
        if( i%3 == 0)
            lenThree[i] = 0;
        else
            lenThree[i] = lenThree[i-5] + 5;
    }
}

int main() {
    precompute();
    int t;
    cin>>t;
    while(t--)
    {
        int n,i;
        cin>>n;
        if( lenThree[n] == -1)
            cout<<"-1\n";
        else
        {
            for(i=1;i<=(n-lenThree[n]);i++)
                cout<<"5";
            for(i=lenThree[n];i>=1;i--)
                cout<<"3";
        
            cout<<endl;
        }
    }
    return 0;
}

