#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
	long long int n,x,y,total=0,curr=0;
    cin>>n;
    vector<pair<long long int, long long int>> vec(n);
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        vec[i] = make_pair(x,y);
    }
    sort(vec.begin(),vec.end());
    for(auto it:vec)
    {
       curr+=it.first;
       total+=it.second-curr;
    }
    cout<<total<<endl;
	return 0;
}
