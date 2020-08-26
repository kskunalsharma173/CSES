#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define mod 1000000007
long long int min(long long int x, long long int y, long long int z)
{
    return min(min(x,y),z);
}
long long int fun(string s1, string s2)
{
    long long int l1 = s1.length();
    long long int l2 = s2.length();
    long long int dp[l1+1][l2+1];
    for(int i=0;i<=l1;i++)
   {    for(int j=0;j<=l2;j++)
       {
           if(i==0)
           {
               dp[i][j]=j;
           }
          else if(j==0)
           {
               dp[i][j]=i;
           }
           else if(s1[i-1]==s2[j-1])
           {
               dp[i][j] = dp[i-1][j-1];
           }
           else
          {

            dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j], dp[i][j-1]))+1;
          }


       }
   }

    return dp[l1][l2];
}

int main()
{
	string s1,s2;
    cin>>s1;
    cin>>s2;

    cout<<fun(s1,s2);
	return 0;
}
