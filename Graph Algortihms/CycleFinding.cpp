#include <functional>
#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <stack>
#include <queue>
#include <string.h>
#include <map>
#include <set>
#define INF 10000000000000000
using namespace std;
#define LL long long int
struct edge
{
    LL a , b , t;
    edge(LL a,LL b,LL t)
    {
        this->a=a;
        this->b=b;this->t=t;
    }
 
};
int main() 
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    LL N,M;
    cin >> N >> M;
    vector<edge> adj;
    while(M--)
    {
        LL x , y;
        cin >> x >> y;
        LL w;
        cin >> w;
        adj.push_back(edge(x,y,w));
    }
    vector<LL> dist(N+1,INF);
    vector<LL> par (N+1,-1);
    dist[1]=0;
    LL x;
    for(LL i=0;i<N+2;i++)
    {
        x=-1;
        for(auto it:adj)
        {
            // if(  dist[it.a] < INF)
            // {
                if( dist[it.a] + it.t < dist[it.b])
                {
                    dist[it.b]=dist[it.a]+it.t;
                    x=it.b ;
                    par[it.b]=it.a;
                }  
            // }
        }
    }
    if(x!=-1)
    {
        cout<<"YES"<<endl;
        for(LL i=0;i<N;i++)
        {
            x=par[x];
        }
        LL curr=par[x];
        vector<LL> ans;
        ans.push_back(x);
        while(curr!=x)
        {
            ans.push_back(curr);
            curr=par[curr];
        }
        ans.push_back(x);
        reverse(ans.begin(),ans.end());
        for(auto it:ans)
            cout<<it<<" ";
 
    }
    else
    {
        cout<<"NO"<<endl;
    }
}