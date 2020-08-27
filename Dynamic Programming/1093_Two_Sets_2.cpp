#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define mod 1000000007
long long int func(long long int n)
{
    long long int a[n+2], sum=0;
    for(int i=1;i<=n;i++)
    {
        a[i]=i;
        sum+=i;
    }
    if(sum%2==1)
    {
        return 0;
    }
    else
    {
    long long int dp[sum/2][n+1];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<=n;i++)
    {
        dp[0][i]=1;
    }
    for(int i=0;i<=sum/2;i++)
    {
        dp[i][0]=0;
    }
    for(int i=1;i<=sum/2;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dp[i][j] = dp[i][j-1];
            if((i)>=a[j])
            {
                dp[i][j] = (dp[i][j-1]+dp[i-a[j]][j-1])%mod;
            }
        }
    }
    return dp[sum/2][n];
    }
}
int main()
{
	long long int n;
    cin>>n;
    cout<<func(n);
	return 0;
}
