#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const int size = 201;

int a[size][size];
int f[size][size];
int n,m;

int main()
{
	scanf("%d%d",&n,&m);
	int y=m/2+1,x=n;
	memset(a,-9999,sizeof(a));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			f[i][j]=max(max(f[i-1][j],f[i-1][j-1]),f[i-1][j+1])+a[i][j];
	printf("%d\n",max(max(f[x][y],f[x][y-1]),f[x][y+1]));
	return 0;
}
