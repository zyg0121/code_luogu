#include <bits/stdc++.h>
using namespace std;

int a[1001],f[1000001];

int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++)
		for(int j=n;j>=a[i];j--)
			f[j]=max(f[j],f[j-a[i]]+a[i]);
	cout<<f[n]<<endl;
	return 0;
}
