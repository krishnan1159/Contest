#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;


int main() {
    int t;
    std::ios_base::sync_with_stdio(false);
    cin>>t;
    while(t--)
    {
        int n,c,m,finTot=0,wrapper = 0,tot;
        
        cin>>n>>c>>m;
        
        finTot = (n/c);
        wrapper = finTot;
        
        while( (wrapper/m) > 0)
        {
            tot = wrapper/m;
            wrapper = wrapper % m + tot;
            
            finTot += tot;
        }
        cout<<finTot<<endl;
    }
    return 0;
}

