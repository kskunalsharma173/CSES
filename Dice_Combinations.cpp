
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define mod 1000000007

int main()
{
	long long int n;
    cin>>n;
    long long int dp[n+2]={0};
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=6 && i-j>=0;j++)
        {
            dp[i] = (dp[i]+dp[i-j])%mod;
        }
    }

    cout<<dp[n]%mod<<endl;

	return 0;
}
