#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define mod 1000000007

long long int fun(long long int a[], long long int n, long long int sum)
{
    long long int dp[sum+1];
    dp[0]=0;
    for(int i=1;i<=sum;i++)
    {
        dp[i] = INT_MAX;
    }
   for(int i=1;i<=sum;i++)
   {    for(int j=0;j<n;j++)
       {
         if(a[j]<=i)
         {

            long long int value = dp[i-a[j]];
            if(value !=INT_MAX && value+1<dp[i])
            {

                dp[i] = value+1;
            }
         }

       }
   }
    if(dp[sum]==INT_MAX)
    {
        dp[sum]=-1;
    }
    return dp[sum];
}

int main()
{
	long long int n;
    cin>>n;
    long long int sum;
    cin>>sum;
    long long int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<fun(a,n,sum);
	return 0;
}
