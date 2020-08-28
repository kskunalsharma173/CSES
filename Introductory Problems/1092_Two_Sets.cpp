#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n;
    cin>>n;
    vector<long long int> vec;
    long long int sum = (n*(n+1))/2;
    if(sum%2==1)
    {
        cout<<"NO"<<endl;
    }
    else
    {   long long int temp = sum/2, s=0, e=0, i=n;
        while(true)
        {
            vec.push_back(i);
            s+=i--;
            e=temp-s;
            if(!e)
            {
                break;
            }
            if(e<=i)
            {
                vec.push_back(e);
                break;
            }
        }
        cout<<"YES"<<endl;
        cout<<vec.size()<<endl;
        for(int i:vec)
        {
            cout<<i<<" ";
        }
        cout<<endl;
        cout<<n-vec.size()<<endl;
        for(int j=i;j>=1;j--)
        {
            if(j==e)
            {
                continue;
            }
            cout<<j<<" ";
        }
    }
    return 0;
}
