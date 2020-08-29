#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
	long long int n;
    cin>>n;
    long long int a[n],ans=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    long long int median=a[n/2];
    for(int i=0;i<n;i++)
    {
        ans+=abs(median-a[i]);
    }
    cout<<ans<<endl;
	return 0;
}
