#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long

const int N = 1e5 + 6;
const int MOD = 1e9 + 7;

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    map<int, int> m;
    set<int> s;
    int x, n; cin >> x >> n;
    s.insert(0);
    s.insert(x);
    m[x] = 1;
    for(int i = 0; i < n; i++) {
        int y; cin >> y;
        auto it = s.lower_bound(y);
        int r = *it;
        it--;
        int l = *it;
        s.insert(y);
        m[r - l]--;
        if(m[r - l] == 0)
            m.erase(r - l);
        ++m[y - l];
        ++m[r - y];
        cout << ((--m.end()) -> first) << " ";
    }
    return 0;
}
