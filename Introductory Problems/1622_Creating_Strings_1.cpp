#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    string x;
    cin>>x;
    sort(x.begin(),x.end());
    vector<string> v;
    v.push_back(x);
    while(next_permutation(x.begin(),x.end()))
    {
        v.push_back(x);
    }
    cout<<v.size()<<endl;
    for(string s:v)
    {
        cout<<s<<endl;
    }
    return 0;
}
