#include <bits/stdc++.h>
using namespace std;
long long int getMid(long long int s, long long int e) { return s + (e -s)/2; }

long long int getSumUtil(long long int *st, long long int ss, long long int se, long long int qs, long long int qe, long long int si)
{
	if (qs <= ss && qe >= se)
		return st[si];

	if (se < qs || ss > qe)
		return 0;

	long long int mid = getMid(ss, se);
	return getSumUtil(st, ss, mid, qs, qe, 2*si+1) +
		getSumUtil(st, mid+1, se, qs, qe, 2*si+2);
}


long long int getSum(long long int *st, long long int n, long long int qs, long long int qe)
{
	if (qs < 0 || qe > n-1 || qs > qe)
	{
		return -1;
	}

	return getSumUtil(st, 0, n-1, qs, qe, 0);
}
long long int constructSTUtil(long long int arr[], long long int ss, long long int se, long long int *st, long long int si)
{
	if (ss == se)
	{
		st[si] = arr[ss];
		return arr[ss];
	}
long long int mid = getMid(ss, se);
	st[si] = constructSTUtil(arr, ss, mid, st, si*2+1) +
			constructSTUtil(arr, mid+1, se, st, si*2+2);
	return st[si];
}
long long int *constructST(long long int arr[], long long int n)
{
	long long int x = (long long int)(ceil(log2(n)));
	long long int max_size = 2*(long long int)pow(2, x) - 1;
	long long int *st = new long long int[max_size];
	constructSTUtil(arr, 0, n-1, st, 0);
	return st;
}
void updateutil(long long int *st, long long int ss, long long int se, long long int i, long long int diff, long long int si)
{
    if(i<ss || i>se)
        return;
    st[si]=st[si]+diff;
    if(ss!=se)
    {
        long long int mid = getMid(ss,se);
        updateutil(st,ss,mid,i,diff,2*si+1);
        updateutil(st,mid+1,se,i,diff,2*si+2);
    }
}
void update(long long int a[], long long int *st, long long int n, long long int i, long long int newval)
{
    if(i<0 || i>n-1)
    {
        return;
    }
    long long int diff = newval - a[i];
    a[i]=newval;
    updateutil(st,0,n-1,i,diff,0);
}
int main()
{
	long long int n,q;
    cin>>n>>q;
    long long int a[n];
    for(long long int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    long long int *st=constructST(a,n);
    while(q--)
    {
        long long int x,y,z;
        cin>>x>>y>>z;
        y--;
        if(x==2)
        {
             z--;
             cout<<getSum(st,n,y,z)<<endl;
        }
        else
        {
            update(a,st,n,y,z);
        }
    }
    return 0;
}
