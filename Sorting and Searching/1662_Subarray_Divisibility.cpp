#include <bits/stdc++.h>
#include <iostream>
using namespace std;
long long int subCount(long long int arr[], long long int n,long long int k)
{
	long long int mod[k];
	memset(mod, 0, sizeof(mod));
	long long int cumSum = 0;
	for (long long int i = 0; i < n; i++) {
		cumSum += arr[i];
        mod[((cumSum % k) + k) % k]++;
	}
    long long int result = 0;
	for (long long int i = 0; i < k; i++)
		if (mod[i] > 1)
			result += (mod[i] * (mod[i] - 1)) / 2;
	result += mod[0];

	return result;
}


int main()
{
	long long int n;
    cin>>n;
    long long int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    long long int k=n;
    cout << subCount(a, n, k) << endl;
	return 0;
}
