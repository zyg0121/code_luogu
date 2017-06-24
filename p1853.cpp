#include <cstdio>
#include <cstring>
#include <algorithm>

const int size = 1000+10;
int w[size],v[size];
int f[size*size];
int s,n,d;

int main() {
	scanf("%d%d%d",&s,&n,&d);
	for(int i=1;i<=d;i++)
		scanf("%d%d",&w[i],&v[i]);
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=d;j++)
			for(int k=w[j];k<=s;k++)
				f[k]=std::max(f[k],f[k-w[j]]+v[j]);
		s+=f[s];
	}
	printf("%d\n",s);
	return 0;
}
