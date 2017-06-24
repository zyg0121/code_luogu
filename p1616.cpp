#include <cstdio>
#include <cstring>
#include <algorithm>

#define Max(a,b) ((a)>(b)?(a):(b))
const int size = 100000+10;

int f[size],w[size],v[size];
int m,T;

int main() {
	scanf("%d%d",&T,&m);
	for(int i=1;i<=m;i++) {
		scanf("%d%d",&w[i],&v[i]);
	}
	for (int i=1;i<=m;i++)
		for (int j=w[i];j<=T;j++) {
			f[j]=Max(f[j],f[j-w[i]]+v[i]);
        }
    printf("%d\n",f[T]);
    return 0;
}
