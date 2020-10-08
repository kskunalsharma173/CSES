#include<bits/stdc++.h>
#define fi(i,a,b) for(ll i = a; i < b; i++)
#define fd(i,a,b) for(ll i = a; i >= b; i--)
#define cfi(container,it) for(auto it = container.begin(); it != container.end(); it++)
#define cfd(container,it) for(auto it = container.rbegin(); it != container.rend(); it++)
#define vi vector<int>
#define vll vector<ll>
#define all(v) (v).begin(), (v).end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back

using namespace std;
using ll = long long;
const int MOD = (int) 1e9 + 7;
const int nax = (int) 2e5 + 20;

int n, q;
vi a, lo(3*nax), hi(3*nax), tree(3*nax);

void init(int i, int l, int r) {
	lo[i] = l;
	hi[i] = r;

	if(l == r) {
		return;
	}

	int m = (l + r)/2;
	init(2*i, l, m);
	init(2*i + 1, m + 1, r);
}

int merge(int u, int v) {
	return min(u, v);
}

void build(int i) {
	int l = lo[i], r = hi[i];
	if(l == r) {
		tree[i] = a[l];
		return;
	}

	build(2*i);
	build(2*i + 1);
	tree[i] = merge(tree[2*i], tree[2*i + 1]);
}

void update(int i, int pos, int val) {
	int l = lo[i], r = hi[i];
	if(l == r && l == pos) {
		tree[i] = val;
		a[l] = val;
		return;
	}

	int m = (l + r)/2;
	if(pos <= m)
		update(2*i, pos, val);
	else
		update(2*i + 1, pos, val);

	tree[i] = merge(tree[2*i], tree[2*i + 1]);
}

int query(int i, int u, int v) {
	int l = lo[i], r = hi[i];
	if(v < l || u > r) {
		return MOD;
	}
	if(u <= l && r <= v) {
		return tree[i];
	}

	int leftChild = query(2*i, u, v);
	int rightChild = query(2*i + 1, u, v);

	return merge(leftChild, rightChild);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>q;
	a.resize(n + 1);

	fi(i, 1, n + 1) {
		cin>>a[i];
	}

	init(1, 1, n);
	build(1);


	int op, u, v;
	fi(i, 0, q) {
		cin>>op>>u>>v;
		if(op == 1) {
			update(1, u, v);
		} else {
			cout<<query(1, u, v)<<'\n';
		}
	}

	return 0;
}
