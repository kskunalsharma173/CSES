#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000
long long int vis[MAX],color[MAX];
vector<long long int> graph[MAX];
bool bfs(long long int src)
{
    queue<long long int> q;
    q.push(src);
    color[src]=1;
    vis[src]=1;
    while(!q.empty())
    {
        long long int f = q.front();
        q.pop();
        for(auto x: graph[f])
        {
            if(color[f]==color[x])
                return false;
            if(!vis[x])
            {
                vis[x]=1;
                color[x]=3-color[f];
                q.push(x);
            }
        }
    }
    return true;
}
bool isBipartite(long long int v)
{
    for(long long int i=0;i<=v;i++)
    {
        if(vis[i]==0 && !bfs(i))
        return false;
    }
    return true;
}
int main()
{
    long long int v,e;
    cin>>v>>e;
    for(int i=0;i<e;i++)
    {
        long long int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    if(isBipartite(v))
    {
        for(int i=1;i<=v;i++)
            cout<<color[i]<<" ";
    }
    else
        cout<<"IMPOSSIBLE"<<endl;
}
