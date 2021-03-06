#include <cstdio>
#include <cstring>
#include <algorithm>

#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
typedef long long LL;

const int size = 500+10;
int f[size][size];
int n,m;
int head[size],nxt[size],w[size];

inline int dfs(int x) {
	if(head[x]==-1) return 0;
	int ret=0;
	for(int i=head[x];i!=-1;i=nxt[i]) {
		int tmp=dfs(i);
		ret+=tmp+1;
		for(int j=ret;j>=0;j--) {
			for(int k=0;k<=tmp;k++)
				if(j-k-1>=0) f[x][j]=Max(f[x][j],f[x][j-k-1]+f[i][k]);
		}
	}
	return ret;
}

int main() {
	scanf("%d%d",&n,&m);
	memset(f,0,sizeof f);memset(head,-1,sizeof head);
	for(int i=1;i<=n;i++) {
		int a;scanf("%d%d",&a,&w[i]);
		nxt[i]=head[a];head[a]=i;
	}
	for(int i=1;i<=n;i++) f[i][0]=w[i];
	f[0][0]=0;
	dfs(0);printf("%d\n",f[0][m]);
	return 0;
}
