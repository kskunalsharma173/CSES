#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define mod 1000000007
long long int fun(long long int a[], long long int n, long long int sum)
{
    long long int dp[sum+1]={0};
    dp[0]=1;
    for(int i=0;i<n;i++)
    {    for(int j=a[i];j<=sum;j++)
       {
          dp[j] = (dp[j]+dp[j-a[i]])%mod;
       }
    }
    return dp[sum]%mod;
}

int main()
{
	long long int n,sum;
    cin>>n;
    cin>>sum;
    long long int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    cout<<fun(a,n,sum);
	return 0;
}
