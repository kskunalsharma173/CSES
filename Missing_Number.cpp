#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
	long long int n;
    cin>>n;
    long long int a[n], i, sum=0;
    for(i=0;i<n-1;i++)
    {
        cin>>a[i];
    }
    sum = (n*(n+1))/2;
    for(int i=0;i<n-1;i++)
    {
        sum -= a[i];
    }
    cout<<sum<<endl;
	return 0;
}
