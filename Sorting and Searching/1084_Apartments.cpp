#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    long long int n,m,x;
    cin>>n>>m>>x;
    long long int a[n],ans=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    multiset<long long int> ms;
    long long int value;
    for(int i=0;i<m;i++)
    {
        cin>>value;
        ms.insert(value);
    }
    for(int i=0;i<n;i++)
    {
        long long int v=a[i]-x;
        auto it = ms.lower_bound(v);
        if(it!=ms.end() && *it<=a[i]+x)
        {
            ms.erase(it);
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
