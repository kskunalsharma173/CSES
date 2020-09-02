#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,k;
    cin>>n>>k;
    pair< ll,ll > p[n];
    for(ll i=0;i<n;i++)
    {
    	ll a,b;
    	cin>>a>>b;
    	p[i]={b,a};
	}
	sort(p,p+n);
	multiset< ll,greater<int> > s;
	ll ans=0;
	for(ll i=0;i<n;i++)
	{
		if(s.empty())
		{
			s.insert(p[i].first);
			ans++;
			k--;
		}
		else
		{
			auto it=s.lower_bound(p[i].second);
			if(it==s.end())
			{
				if(k>0)
				{
					k--;
					ans++;
					s.insert(p[i].first);
				}
			}
			else
			{
				s.erase(it);
				s.insert(p[i].first);
				ans++;
			}
		}
	}
	cout<<ans;
    return 0;
}
