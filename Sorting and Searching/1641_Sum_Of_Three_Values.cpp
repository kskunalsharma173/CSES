#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
	long long int n,s;
    cin>>n>>s;
    long long int a[n],b[n],value;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        a[i]=value;
        b[i]=a[i];
    }
    sort(a,a+n);
    long long int x,y,z,flag=0;
    for(int i=0;i<n-2;i++)
    {
        long long int j=i+1,k=n-1;
        while(j<k)
        {
            if(a[i]+a[j]+a[k]==s)
            {
                x=i;
                y=j;
                z=k;
                flag=1;
                break;
            }
            else if(a[i]+a[j]+a[k]>s)
            {
                k--;
            }
            else
                j++;
        }
    }
    if(flag==0)
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
    else
    {
      long long ind1=INT_MIN,ind2=INT_MIN,ind3=INT_MIN;
      for(int i=0;i<n;i++)
      { if(b[i]==a[x] && ind1==INT_MIN)
        {
            ind1=i+1;
        }
        else if(b[i]==a[y] && ind2==INT_MIN)
        {
            ind2=i+1;
        }
        else if(b[i]==a[z] && ind3==INT_MIN)
        {
            ind3=i+1;
        }
      }
        cout<<ind1<<" "<<ind2<<" "<<ind3<<endl;
	}
    return 0;
}
