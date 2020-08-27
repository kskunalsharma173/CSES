#include <bits/stdc++.h>
#include <iostream>
using namespace std;
long long int func(long long int a, long long int b)
{
    long long int dp[a+1][b+1];
    for(int i=1;i<=a;i++)
    {
        for(int j=1;j<=b;j++)
        {
            if(i==j)
            {
                dp[i][j]=0;
                continue;
            }
            long long int v1,v2;
            v1 = v2 = INT_MAX;
            for(int ii=1;ii<j;ii++)
            {
               v1 = min(v1,1+dp[i][j-ii]+dp[i][ii]);
            }
             for(int ii=1;ii<i;ii++)
            {
               v2 = min(v2,1+dp[i-ii][j]+dp[ii][j]);
            }
            dp[i][j] = min(v1,v2);
        }
    }
    return dp[a][b];
}
int main()
{
	long long int a,b;
    cin>>a>>b;
    cout<<func(a,b);
	return 0;
}
