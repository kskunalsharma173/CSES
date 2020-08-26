#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    long long int n;
    cin>>n;
    long long int a[n], i;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    long long int diff=0,ans=0;
    for(int i=0;i<n-1;i++)
    {
        if(a[i]>a[i+1])
        {
            diff = a[i]-a[i+1];
            a[i+1] = a[i+1]+diff;
        }
        else
        {
            continue;
        }
        ans+=diff;
    }
    cout<<ans<<endl;
	return 0;
}
