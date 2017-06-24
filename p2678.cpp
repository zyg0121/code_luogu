#include <bits/stdc++.h>
using namespace std;

int L,n,m,a[50005],ans,l,r;

bool cheak(int x)
{
    int sum,last;
    sum=0;last=0;
    for (int i=0;i<=n;i++)
    {
        if (a[i]-last<x) 
		{
			sum+=1;
			continue;
		}
        last=a[i];
    }
    if (sum>m) 
		return 0;
    return 1;
}
int main()
{
    ios::sync_with_stdio(false);
	cin>>L>>n>>m;
    for (int i=0;i<n;i++)
		cin>>a[i];
    a[n]=L;
    l=1;r=L;
    while (l<=r)
	{
        int mid=(l+r)/2;
        if (cheak(mid)) 
		{
			ans=mid; 
			l=mid+1;
		}
        else r=mid-1;
    }
	cout<<ans<<endl;
	return 0;
}
