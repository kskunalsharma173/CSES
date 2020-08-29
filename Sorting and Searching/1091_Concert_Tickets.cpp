#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int n, m, curr, ticket;
    cin >> n >> m;
    multiset<long long int, greater<int>> tickets;
    while (n--)
    {
        cin >> ticket;
        tickets.insert(ticket);
    }
    while (m--)
    {
        cin >> curr;
        auto it = tickets.lower_bound(curr);
        if (it == tickets.end())
        {
            cout<<-1<<endl;
        }
        else
        {
            cout<<*it<<endl;
            tickets.erase(it);
        }
    }
    return 0;
}
