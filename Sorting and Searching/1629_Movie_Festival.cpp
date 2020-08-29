#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long int n,x,y,curr_end=0,i,ans=0;
	vector<pair<long long int, long long int>> vec;
	cin >> n;
	for(i=0;i<n;i++)
	{
		cin>>x>>y;
        vec.push_back(make_pair(y, x));
	}
    sort(vec.begin(), vec.end());
	for (auto ele : vec)
	{
		if (ele.second >= curr_end)
		{
			curr_end = ele.first;
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
