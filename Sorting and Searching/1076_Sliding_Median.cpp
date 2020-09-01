#include <bits/stdc++.h>

using namespace std;

int n, k;
set<pair<int, int>> low;
set<pair<int, int>> high;

void add(int x, int index)
{
	pair<int, int> f = { x, index };
	if (high.empty() || x < high.begin()->first)
		low.insert(f);
	else
		high.insert(f);
	if ((int)low.size() - (int)high.size() >= 2)
	{
		pair<int, int> t = *prev(low.end(), 1);
		high.insert(t);
		low.erase(prev(low.end(), 1));
	}
	if ((int)high.size() > (int)low.size())
	{
		pair<int, int> t = *high.begin();
		low.insert(t);
		high.erase(high.begin());
	}
}

void remove(int x, int index)
{
	pair<int, int> f = { x, index };
	low.erase(f);
	high.erase(f);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;
	for (int i = 0; i < k; i++)
		add(a[i], i);
	cout << prev(low.end(), 1)->first << " ";
	for (int i = k; i < n; i++)
	{
		remove(a[i - k], i - k);
		add(a[i], i);
		cout << prev(low.end(), 1)->first << " ";
	}
	return 0;
}
