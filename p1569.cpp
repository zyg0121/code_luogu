#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

long long s[1001];
int a[1001],f[1001];
int n;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(s[i]>=0)
			f[i]=1;
		for(int j=1;j<=i-1;j++)
			if((s[i]-s[j]>=0) and (f[j]+1>f[i]) and (f[j]>0))
				f[i]=f[j]+1;
	}
	if(f[n]==0)
		cout<<"Impossible"<<endl;
	else
		cout<<f[n]<<endl;
	return 0;
}
