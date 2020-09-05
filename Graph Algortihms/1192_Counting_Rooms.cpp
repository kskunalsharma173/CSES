#include <bits/stdc++.h>
#include <iostream>
using namespace std;
long long int n,m, mat[1001][1001];
void dfs(long long int i, long long int j)
{
    if(i<0 || i>=n || j<0 || j>=m)
        return;
    if(mat[i][j]==0)
    {
        return;
    }
    mat[i][j]=0;
    dfs(i+1,j);
    dfs(i-1,j);
    dfs(i,j-1);
    dfs(i,j+1);

}
int main()
{
	long long int i,j;
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            char ch;
            cin>>ch;
            if(ch=='#')
                mat[i][j]=0;
            else
                mat[i][j]=1;
        }
    }
   long long int count =0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(mat[i][j]==1)
            {
                dfs(i,j);
                count++;
            }
        }
    }
    cout<<count<<endl;
	return 0;
}
