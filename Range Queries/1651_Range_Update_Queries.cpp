#include <bits/stdc++.h>
#define ll long long
#define mm 200002
#define nn '\n'

using namespace std;

int n,q,w,x,y,z,a[mm];
ll seg[mm*5],lazy[mm*5];

void turbo () {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}
void input () {

    cin >> n >> q;
    for(int i=1; i<=n; i++)
        cin >> a[i];
}
void down (int id) {

    ll gt=lazy[id];

    seg[id*2]+=gt;
    lazy[id*2]+=gt;

    seg[id*2+1]+=gt;
    lazy[id*2+1]+=gt;

    lazy[id] = 0;
}
void update (int id, int l, int r, int u, int v, int gt) {

    if(v < l || r < u) return;
    if(u <= l && r <= v) {
        seg[id]+=gt;
        lazy[id]+=gt;
        return;
    }

    int mid=(l+r)/2;

    down(id);

    update(id*2,l,mid,u,v,gt);
    update(id*2+1,mid+1,r,u,v,gt);
}
ll gett (int id, int l, int r, int u, int v) {

    if(v < l || r < u) return 0;
    if(u <= l && r <= v) return seg[id];

    int mid=(l+r)/2;

    down(id);

    return (gett(id*2,l,mid,u,v)+
            gett(id*2+1,mid+1,r,u,v));
}
void output () {

    ll res=0;
    for(int i=1; i<=q; i++) {

        cin >> w;
        if(w == 1) {
            cin >> x >> y >> z;
            update(1,1,n,x,y,z);
            continue;
        }

        cin >> x;
        res=gett(1,1,n,x,x);
        res+=a[x]; cout << res << nn;
    }

    return;
}

int main () {

    turbo();
    input();
    output();
}
