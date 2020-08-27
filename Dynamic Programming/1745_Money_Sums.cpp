#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
	long long int n;
    cin>>n;
    long long int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    long long int sum=n*1000;
    vector<vector<bool>> dp(n+1,vector<bool>(sum+1,false));
    dp[0][0]=true;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            if(j==0)
            {
                dp[i][j]=true;
                continue;
            }
            dp[i][j]=dp[i-1][j];
            if(j>=a[i-1])
            {
                dp[i][j] = dp[i][j] | dp[i-1][j-a[i-1]];
            }
        }
    }
    vector<long long int> result;
    for(int i=1;i<=sum;i++)
    {
        if(dp[n][i])
            result.push_back(i);
    }
    cout<<result.size()<<endl;
    for(int i:result)
        cout<<i<<" ";
    cout<<endl;
	return 0;
}
