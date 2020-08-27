#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define mod 1000000007
long long int dp[5003][5003];
long long int func(long long int i,long long int j, long long int a[], long long int sum)
{
   if(i==j)
       return max(a[i],a[j]);
    if(dp[i][j]!=-1)
        return dp[i][j];
    dp[i][j] = max((sum-func(i+1,j,a,sum-a[i])), (sum-func(i,j-1,a,sum-a[j])));
    return dp[i][j];
}
int main()
{
	long long int n;
    cin>>n;
    long long int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    long long int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<func(0,n-1,a,sum);
	return 0;
}
