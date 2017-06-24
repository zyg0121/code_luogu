#include <cstdio>
#include <cstring>
#include <algorithm>

const int size = 50+10;
typedef long long LL;

LL w[size],f[size][size];
int g[size][size];
int n;

void print(int l,int r);

int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%lld",&w[i]);
		f[i][i]=w[i];g[i][i]=i;
	}
	for(int i=n;i>0;i--)
		for(int j=i+1;j<=n;j++)
			for(int k=i;k<=j;k++) {
				int x=f[i][k-1],y=f[k+1][j];
				if(x==0) x=1;if(y==0) y=1;
				if(f[i][j]<(x*y+w[k])) {
					f[i][j]=x*y+w[k];g[i][j]=k;
				}
			}
	printf("%d\n",f[1][n]);
	print(1,n);
	puts("");
	return 0;
}

void print(int l,int r) {
	if(l>r) return ;
	int k=g[l][r];
	printf("%d ",k);
	print(l,k-1);print(k+1,r);
}

/*
  5
  5 7 1 2 10
*/
