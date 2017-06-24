#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const int size=1001;
long long n,x;
long long f[size][size],win[size],lose[size],use[size];

int main()
{
	scanf("%d%d",&n,&x);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&lose[i],&win[i],&use[i]);
	for(int i=1;i<=n;i++)
		for(int j=0;j<=x;j++)
		{
			if(j>=use[i])
				f[i][j]=max(f[i-1][j-use[i]]+win[i],f[i-1][j]+lose[i]);
			else
				f[i][j]=f[i-1][j]+lose[i];
		}
	printf("%lld\n",f[n][x]*5);
	return 0;
}
