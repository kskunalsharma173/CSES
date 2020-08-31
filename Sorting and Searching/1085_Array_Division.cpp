#include <bits/stdc++.h>
#include <iostream>
using namespace std;
long long int check(long long int mid, long long int a[], long long int n, long long int t)
{
    long long int count=1,sum=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]>mid)
            return false;
        sum+=a[i];
        if(sum>mid)
        {
            count++;
            sum=a[i];
        }
    }
    if(count<=t)
        return true;
    return false;
}
int main()
{
	long long int n,t,sum;
    cin>>n>>t;
    long long int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    long long int low=1,high=sum,mid,ans=0;
    while(low<=high)
    {
        mid = (low+high)/2;
        if(check(mid,a,n,t))
        {
            ans=mid;
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    cout<<ans<<endl;
	return 0;
}
