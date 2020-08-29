#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    long long int n;
    cin>>n;
    long long int a[n+2];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    map<long long int, long long int> map;
    long long int i=1,res=0;
    for(int j=1;j<=n;j++)
    {
        i=max(i,map[a[j]]+1);
        res=max(res,j-i+1);
        map[a[j]]=j;
    }
    cout<<res<<endl;
    return 0;
}
