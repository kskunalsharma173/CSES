#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define mod 1000000007
int main()
{
	long long int n;
    cin>>n;
    bool grid[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            char ch;
            cin>>ch;
            if(ch=='.')
                grid[i][j]=0;
            else
                grid[i][j]=1;
        }
    }
    long long int dp[n+1][n+1];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i== 0 && j==0 && grid[i][j]==0)
                dp[i][j]=1;
            else if(grid[i][j])
                dp[i][j]=0;
            else
            {
                long long int v1,v2;
                v1 = i>=1 ? dp[i-1][j] : 0;
                v2 = j>=1 ? dp[i][j-1] : 0;
                dp[i][j] = (v1 + v2)%mod;
            }
        }
    }
    if(grid[n-1][n-1])
        cout<<0;
    else
        cout<<dp[n-1][n-1];
	return 0;
}
