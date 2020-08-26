#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    long long int n;
    cin>>n;
    string str="";
    if(n==1)
    {
        cout<<1<<endl;
    }
    else if(n<=3)
    {
        cout<<"NO SOLUTION"<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        if(i%2==0)
        {
            cout<<i<<" ";
        }
        else
        {
            str+= to_string(i)+" ";
        }
    }
    cout<<str;
	return 0;
}
