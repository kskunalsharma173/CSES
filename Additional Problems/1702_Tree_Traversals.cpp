#include <iostream>
#include<bits/stdc++.h>
using namespace std;
long long int preIndex = 0;
long long int search(long long int arr[], long long int startIn, long long int endIn,long long int data)
{
	long long int i = 0;
	for (i = startIn; i < endIn; i++)
	{
		if (arr[i] == data)
		{
			return i;
		}
	}
	return i;
}
void printPost(long long int arr[], long long int pre[],long long int inStrt, long long int inEnd)
{
	if (inStrt > inEnd)
	{
		return;
	}
	long long int inIndex = search(arr, inStrt, inEnd,pre[preIndex++]);
	printPost(arr, pre, inStrt, inIndex - 1);
	printPost(arr, pre, inIndex + 1, inEnd);
	cout << arr[inIndex] << " ";
}

int main()
{
	long long int n;
    cin>>n;
    long long int pre[n+1],in[n+1];
    for(int i=0;i<n;i++)
    {
        cin>>pre[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>in[i];
    }
	printPost(in, pre, 0, n - 1);
}

/*
Using unordered_map in O(n) but result is tle
#include<bits/stdc++.h>
using namespace std;
long long int preindex=0;
void func(long long int in[], long long int pre[], long long int st, long long int en, unordered_map<long long int, long long int> map)
{
    if(st>en)
    {
        return;
    }
    long long int index = map[pre[preindex++]];
    func(in,pre,st,index-1,map);
    func(in,pre,index+1,en,map);
    cout<<in[index]<<" ";
}
int main()
{
    long long int n;
    cin>>n;
    long long int pre[n+1],in[n+1];
    for(int i=0;i<n;i++)
    {
        cin>>pre[i];
    }
    unordered_map<long long int, long long int> map;
    for(int i=0;i<n;i++)
    {
        cin>>in[i];
        map[in[i]]=i;
    }
    func(in,pre,0,n-1,map);
    return 0;
}

*/
