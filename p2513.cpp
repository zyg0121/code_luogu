#include <cstdio>
#include <cstring>
#include <algorithm>

const int size = 1e3+10,mod = 1e4;

int f[size][size],n,m,sum;

int main() {
	scanf("%d%d",&n,&m);
	f[1][0]=1;
	for(int i=2;i<=n;i++) {
		sum=0;
		for(int j=0;j<=m;j++) {
			sum=(sum+f[i-1][j])%mod;
			f[i][j]=sum%mod;
			if(j-i+1>=0) {
				sum-=f[i-1][j-i+1];
				sum=(sum+mod)%mod;
			}
		}
	}
	printf("%d\n",f[n][m]);
	return 0;
} 
