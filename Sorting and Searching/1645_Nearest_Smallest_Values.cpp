#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
	long long int n;
    cin>>n;
    long long int a[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    stack<pair<long long int, long long int>> st;
    for(int i=1;i<=n;i++)
    {
        while(!st.empty() && st.top().first>=a[i])
            st.pop();
        if(st.empty())
            cout<<0<<" ";
        else
            cout<<st.top().second<<" ";
        st.push({a[i],i});
    }
	return 0;
}
