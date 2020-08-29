#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
	long long int n;
    cin>>n;
    long long int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    long long int sum=0,maxi=INT_MIN;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
        maxi=max(maxi,sum);
        if(sum<0)
            sum=0;

    }
    cout<<maxi<<endl;
	return 0;
}
