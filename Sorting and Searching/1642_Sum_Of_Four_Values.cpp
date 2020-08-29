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
    long long int x,y,z,w,flag=0;
    map<long long int, vector<pair<long long int, long long int>>> map;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            long long int sum = (s-(a[i]+a[j]));
            if(map.find(sum)!=map.end())
            {
                for(auto pair:map.find(sum)->second)
                {
                    long long int xx,yy;
                    xx = pair.first;
                    yy = pair.second;
                    if (xx != i && xx != j && yy != i && yy != j)
                    {
                        w=i;
                        x=j;
                        y=xx;
                        z=yy;
                        flag=1;
                        break;
                    }

                if(flag==1)
                    break;
                }
                if(flag==1)
                    break;
            }
            else
            {
                map[a[i]+a[j]].push_back(make_pair(i,j));
            }
        }

    }
    if(flag==0)
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
    else
    {
      long long ind1=INT_MIN,ind2=INT_MIN,ind3=INT_MIN,ind4=INT_MIN;
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
       else if(b[i]==a[w] && ind4==INT_MIN)
        {
            ind4=i+1;
        }
      }
        cout<<ind1<<" "<<ind2<<" "<<ind3<<" "<<ind4<<endl;
	}
    return 0;
}
