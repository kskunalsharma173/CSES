#include <bits/stdc++.h>
#define forn(i, n) for (long long int i = 0; i < n; i++)
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k; cin >> n >> k;
    vector<pair<int, int>> v;
    forn (i, n) {
        int x, y; cin >> x >> y;
        v.push_back({y, x});
    }
    sort (v.begin(), v.end());
    int cnt = 0;
    multiset <int> p;
    forn (i, k) p.insert(0);
    for (auto i:v) {
        auto it = p.upper_bound(i.second);
        if (it == p.begin())
            continue;
        it--;
        cnt++;
        p.erase(it);
        p.insert(i.first);
    }
    cout << cnt << "\n";
    return 0;
}
