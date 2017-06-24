#include <cstdio>
#include <cstring>
#include <algorithm>

#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
typedef long long LL;

const int size = 100+10;
int f[size][size],g[size][size];
int s[size];
int n,x,minn=1<<30,maxx;

int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		int x;scanf("%d",&x);
		s[i]=s[i-1]+x;
	}
	for(int i=n+1;i<=2*n;i++)
		s[i]=s[i-n]+s[n];
	memset(f,127/3,sizeof f);
	
	for(int i=1;i<=2*n;i++)
		f[i][i]=0;
	for(int k=1;k<=n;k++) {
		for(int i=1;i<=2*n-k;i++) {
			int j=i+k;
			for(int t=i;t<j;t++)
				f[i][j]=Min(f[i][t]+f[t+1][j]+s[j]-s[i-1],f[i][j]);
		}
	}
	for(int i=1;i<=n;i++)
		minn=Min(minn,f[i][i+n-1]);
	printf("%d\n",minn);

	for(int k=1;k<=n;k++) {
		for(int i=1;i<=2*n-k;i++) {
			int j=i+k;
			for(int t=i;t<j;t++)
				g[i][j]=Max(g[i][t]+g[t+1][j]+s[j]-s[i-1],g[i][j]);
		}
	}
	for(int i=1;i<=n;i++)
		maxx=Max(maxx,g[i][i+n-1]);
	printf("%d\n",maxx);
	
	return 0;
}
