#include <bits/stdc++.h>
using namespace std;

int n,a[100001],ans=2,top=0;

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int p;cin>>p;
		if(a[top]!=p)
			a[++top]=p;
	}
	if(top<=2)
		return cout<<top<<endl,0;
	for(int i=2;i<=top-1;i++)
		if((a[i]>a[i-1]&&a[i]>a[i+1])||(a[i]<a[i-1]&&a[i]<a[i+1]))
			ans++;
	cout<<ans<<endl;
	return 0;
}
