#include <cstdio>
#include <cstring>
#include <algorithm>

const int size = 2500+10;
int n,m,sum[size],f[size];

int main() {
	scanf("%d%d",&n,&m);
	sum[0]=m;
	for(int i=1,a;i<=n;i++) {
		scanf("%d",&a);
		sum[i]=sum[i-1]+a;
	}
	memset(f,0x3f,sizeof f);
	f[0]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			f[j]=std::min(f[j],f[j-i]+sum[i]+m);
	printf("%d\n",f[n]-m);
	return 0;
}
