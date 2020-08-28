#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
	string s;
    cin>>s;
    unordered_map<char, long long int> map;
    long long int len = s.length();
    long long int count=0;
    for(int i=0;i<len;i++)
    {
        char ch = s[i];
        map[ch]++;
    }
    long long int st=0,e=len-1,flag=0;
    char c;
    string s2(len,'*');
    for(auto it:map)
    {
        while(it.second>0)
        { if((it.second)%2==0)
          {
            s2[st]=it.first;
            s2[e]=it.first;
            st++;
            e--;
            it.second = it.second-2;
          }
         else
         {
            flag++;
             c = it.first;
            it.second--;
         }
        }
    }
    if(flag>=2 || (flag==1 && len%2==0))
    {
        cout<<"NO SOLUTION"<<endl;
    }
    else
    {
        if(flag==1)
        {s2[len/2]=c;
        }
        for(int i=0;i<len;i++)
        {
            cout<<s2[i]<<"";
        }
    }
    return 0;
}
