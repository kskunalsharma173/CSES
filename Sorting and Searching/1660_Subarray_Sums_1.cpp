#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
	long long int n,sum;
    cin>>n>>sum;
    long long int a[n+1];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    unordered_map<long long int, long long int> map;
    long long int total=0,res=0;
    for(int i=0;i<n;i++)
    {
        total+=a[i];
        if(total==sum)
            res++;
       if(map.find(total-sum)!=map.end())
           res+=map[(total-sum)];
        map[total]++;
    }
    cout<<res<<endl;
	return 0;
}
