#include <bits/stdc++.h>
using namespace std;

int f[301][301];
int n;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++)
		for(int j=i+1;j<=n;j++)
			scanf("%d",&f[i][j]);
	for(int i=2;i<=n;i++)
		for(int j=i;j<=n;j++)
			f[1][j]=min(f[1][j],f[1][i]+f[i][j]);
	cout<<f[1][n]<<endl;
	return 0;
}
