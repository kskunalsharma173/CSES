#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    string s;
    cin>>s;
    long long int n = s.length();
    long long int ans=1,max=1;
    for(int i=0;i<n-1;i++)
    {
        if(s[i]==s[i+1])
        {
            ans++;
        }
        else
        {
            ans=1;
        }
        if(max < ans)
            max = ans;
    }
    cout<<max<<endl;
	return 0;
}
