#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    long long int n,x;
    cin>>n>>x;
    long long int a[n],count=0,sum=0;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
   long long int low=0,high=n-1;
    while(low<=high)
    {
        sum=a[low]+a[high];
        if(sum<=x)
        {
            low++;
            high--;
            count++;
        }
        else
        {
            high--;
            count++;
        }

    }
    cout<<count<<endl;
    return 0;
}
