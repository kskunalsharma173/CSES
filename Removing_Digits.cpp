#include <bits/stdc++.h>
#include <iostream>
using namespace std;
long long int fun(long long int n)
{
    long long int dp[n+1]={0};
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        long long int temp = i;
        long long int mini = INT_MAX;
        while(temp!=0)
        {
            long long int unit = temp%10;
            temp = temp/10;
            if(unit==0){
                continue;
            }
            mini = min(1+dp[i-unit],mini);
        }
        dp[i] = mini;
    }
    return dp[n];
}

int main()
{
	long long int n;
    cin>>n;
    cout<<fun(n);
	return 0;
}
