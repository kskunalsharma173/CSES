#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
	long long int n,x;
    cin>>n>>x;
    vector<pair<long long int, long long int>> a(n);
    for(long long int i=0;i<n;i++)
    {
       cin>>a[i].first;
	   a[i].second=i+1;
    }
    sort(a.begin(),a.end());
    long long int st=0,en=n-1;
    while(st<en)
    {
        if(a[st].first+a[en].first==x)
        {
            cout<<a[st].second<<" "<<a[en].second<<endl;
            return 0;
        }
        else if(a[st].first+a[en].first<x)
        {
            st++;
        }
        else
            en--;
    }
    cout<<"IMPOSSIBLE"<<endl;
	return 0;
}
