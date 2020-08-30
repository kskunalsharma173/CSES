#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
	long long int n,t;
    cin>>n>>t;
    long long int a[n],maxi=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        maxi=max(maxi,a[i]);
    }
    long long int l = 0, r = 1e18, mid, curr_output, ans=0;
	while (l <= r)
	{
		mid = l + (r - l) / 2;
		curr_output = 0;
		for (long long int ele : a)
		{
			curr_output += min((mid / ele),(long long int)1e9);
       }
		if (curr_output >= t)
		{
			ans = mid;
			r = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
	}
	cout<<ans<<endl;
	return 0;
}
