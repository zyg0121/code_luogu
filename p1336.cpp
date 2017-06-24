#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

const int size = 20000+10;
typedef long long LL;

int n,m;
LL f[size];

int main() {
	memset(f,27,sizeof(f));
	scanf("%d%d",&m,&n);
	f[0]=0;
	for(int i=1,a,b;i<=n;i++) {
		scanf("%d%d",&a,&b);
		for(int j=m;j>=0;j--) 
			for(int k=1;k<=j;k++)
				f[j]=std::min(f[j],f[j-k]+a*(LL)pow(k,b));
	}
	printf("%lld\n",f[m]);
	return 0;
}
