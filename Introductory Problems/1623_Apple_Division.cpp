#include <bits/stdc++.h>
#include <iostream>
using namespace std;
long long int mini,total;
void func(long long int ind, long long int sum, long long int a[], long long int n)
{
  if(ind==n)
  {
      long long int x,y;
      x = sum;
      y = total-sum;
      mini=min(mini, abs(x-y));
      return;
  }
  func(ind+1,sum,a,n);
  func(ind+1,sum+a[ind],a,n);
}
int main()
{
	long long int n;
    cin>>n;
    long long int a[n],sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    sort(a,a+n);
    total = mini = sum;
    func(0,0,a,n);
    cout<<mini<<endl;
	return 0;
}
