#include <functional>
#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#define mod 1000000007
using namespace std;
#define LL long long int
LL cycleStart=-1;
LL cycleEnd=-1;
bool dfs(LL src,LL par,vector<LL> *adj,vector<LL> &color,vector<LL> &parent)
{
    color[src]=2;
    if(parent[src]==0)
        parent[src]=par;
    for(auto it:adj[src])
    {
        if(parent[it]==0)
        parent[it]=src;
        // if(it==par)
        // {
        //     continue;
        // }
        if(color[it]== 2)
        {
            cycleStart = it;
            cycleEnd   =  src;
            return true;
        }
        if(color[it]==0 and dfs(it,src,adj,color,parent))
        {
            return true;
        }
    }
    color [src] = 1;
    return false;
}
int main() 
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    LL N,K;
    cin >> N >> K;
    vector<LL> adj[N+1];
    while(K--)
    {
        LL x,y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    vector<LL> color(N+1,0);
    bool ok=false;
    vector<LL> parent(N+1,0);
    for(LL i=1;i<=N;i++)
    {
        if(color[i]==0)
        {
            if(dfs(i,-1,adj,color,parent)==true)
            {
                ok=true;
                break;
            }
        }
    }
    if(cycleStart==-1)
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
    else
    {
        LL node=cycleEnd;
        vector<LL> ans;
        while(node!=cycleStart and node!=-1)
        {
            ans.push_back(node);
            node=parent[node];
        }   
        cout<<ans.size()+2<<endl;
        reverse(ans.begin(),ans.end());
        ans.push_back(cycleStart);
        cout<<cycleStart<<" ";
        for(auto it:ans)
            cout<<it<<" ";
    }
}