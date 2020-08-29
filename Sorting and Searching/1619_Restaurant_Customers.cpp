#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long int n,maxi=0,ans=0,x,y;
    vector<pair<long long int, bool>> vec;
    cin>>n;
    while(n--)
    {
        cin>>x>>y;
        vec.push_back(make_pair(x,true));
        vec.push_back(make_pair(y,false));
    }
    sort(vec.begin(),vec.end());
    for(int i=0;i<vec.size();i++)
    {
       maxi += vec[i].second ? 1 : -1;
       ans = max(maxi,ans);
    }
    cout<<ans<<endl;
	return 0;
}
