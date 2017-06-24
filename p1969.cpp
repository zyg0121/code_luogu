#include <bits/stdc++.h>
using namespace std;

int n;
int a[100001];
int maxx,ans;

int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		if(a[i]>maxx)
			ans+=a[i]-maxx;
		maxx=a[i];	
	}
	cout<<ans<<endl;
	return 0;
}
