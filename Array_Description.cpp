#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define mod 1000000007
long long int fun(long long int n, long long int a[], long long int m)
{
    long long int dp[n+2][m+2];
    memset(dp,0,sizeof(dp));

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
           if(i!=1)
           {
               if(a[i]==0 || a[i]==j)
               {
                   dp[i][j] = ((dp[i-1][j-1] + dp[i-1][j])%mod + dp[i-1][j+1])%mod;
               }
               else
               {
                   dp[i][j] = 0;
               }
           }
            else
            {
                if(a[i]==0 || a[i]==j)
                {
                    dp[i][j]=1;
                }
                else
                {
                    dp[i][j]=0;
                }
            }
        }
    }
    long long int max=0;
    for(int i=1;i<=m;i++)
    {
            max = (max + dp[n][i])%mod;
    }
    return max;
}
int main()
{
  long long int n;
  cin>>n;
  long long int m;
  cin>>m;
  long long int a[n+1];
  for(int i=1;i<=n;i++)
  {
      cin>>a[i];
  }
  cout<<fun(n,a,m);
  return 0;
}
