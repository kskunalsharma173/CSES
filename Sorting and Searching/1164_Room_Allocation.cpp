#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
	long long int n,x,y;
    cin>>n;
    vector<pair<long long int, pair<long long int, long long int>>> vec;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y;
        vec.push_back({x, {-1, i}});
        vec.push_back({y, {1, i}});
    }
    sort(vec.begin(),vec.end());
    vector<long long int> rooms;
    long long int occupied = 0, max_rooms = 0, in_or_out, ind, ans[200005];
    for(auto it: vec)
    {
        in_or_out = it.second.first;
        ind = it.second.second;
        if(in_or_out==1)
        {
            rooms.push_back(ans[ind]);
        }
        else if(occupied == rooms.size())
        {
            ans[ind]=++max_rooms;
        }
        else
        {
            ans[ind] = rooms[occupied++];
        }
    }
    cout << max_rooms << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}
