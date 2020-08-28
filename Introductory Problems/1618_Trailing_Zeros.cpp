#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
	long long int n;
    cin>>n;
    long long int count=0;
    for(int i=5;n/i>=1;i*=5)
    {
        count+= n/i;
    }
    cout<<count<<endl;
	return 0;
}
