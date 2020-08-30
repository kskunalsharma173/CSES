#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define _fi(n) for(int i = 0;i < n;i++)
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(0);

    long long int x, n;
    cin>>x>>n;
    set<long long int>s;
    s.insert(0);
    s.insert(x);

    multiset<long long int, greater<long long int>>ans;
    ans.insert(x);
    while(n){
        long long int p;cin>>p;
        s.insert(p);
        auto it = s.lower_bound(p);
        auto left = it;
        auto right = it;
        left--;
        right++;

        ans.erase(ans.find(*right-*left));
        ans.insert(*right-p);
        ans.insert(p-*left);
        n--;
        cout << *ans.begin()<<" ";
    }

    return 0;
}
