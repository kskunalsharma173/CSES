#include<bits/stdc++.h>
using namespace std;
void dfs(long long int i, vector<vector<long long int>>& vec, vector<long long int>& vis)
{
    vis[i]=1;
    for(auto v:vec[i])
    {
        if(!vis[v])
            dfs(v,vec,vis);
    }
}
int main()
{
    long long int n,e;
    cin>>n>>e;
    vector<vector<long long int>> vec(n);
    for(int i=0;i<e;i++)
    {
        long long int x,y;
        cin>>x>>y;
        x--;
        y--;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    vector<long long int> vis(n);
    vector<long long int> b;
    dfs(0,vec,vis);
    for(int i=1;i<n;i++)
    {
        if(!vis[i])
        {
            b.push_back(i);
            dfs(i,vec,vis);
        }
    }
    cout<<b.size()<<endl;
    for(auto x:b)
       cout<<1<<" "<<x+1<<endl;
}
