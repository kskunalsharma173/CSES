#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long int func(long long int b,long long int n)
{
    long long int ans=1;
    for(int i=1;i<=n;i++){
        ans = (ans*b)%mod;
    }
    return ans;
}
int main()
{
    long long int n;
    cin>>n;
    cout<<func(2,n);
    return 0;
}
