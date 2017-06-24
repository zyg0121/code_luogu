#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int f[2001][2001];
int a[2001][2001];
int n,m;
int ans=0x7fffffff;

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	memset(f,0x7fffffff,sizeof(f));
	for(int i=1;i<=m;i++)
		f[i][1]=a[i][1];
	for(int j=2;j<=n;j++)
		for(int i=1;i<=m;i++)
			if(i==1)
				f[i][j]=a[i][j]+min(f[i][j-1],f[m][j-1]);
			else
				f[i][j]=a[i][j]+min(f[i][j-1],f[i-1][j-1]);
	for(int i=1;i<=m;i++)
		ans=min(ans,f[i][n]);
	cout<<ans<<endl;
	return 0;
}
