#include <iostream>
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
using ll = long long int;
void solve(){
    int n,a,b;
    cin>>n>>a>>b;
    vector<ll> prefixsum(n+1);
    prefixsum[0] = 0;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        prefixsum[i] = prefixsum[i-1] + x;
    }
    multiset<ll> curr;
    ll ans = -2e18;
    for(int i=a;i<=n;i++){
        if(i>b){
            curr.erase(curr.find(prefixsum[i-b-1]));
        }
        curr.insert(prefixsum[i-a]);
        ans = max(ans, prefixsum[i] - *curr.begin());
    }
    cout<<ans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
