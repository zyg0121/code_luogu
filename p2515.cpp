#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
typedef long long LL;

const int size = 100050;

int head[size],to[size],nxt[size],v[size],w[size],low[size],dfn[size],zhan[size],vis[size];
int cnt,tt,sum,tot,w2[size],v2[size],fr[size];
int n,m,f[1010][1010],ru[size];
std::vector<int> p[size];

inline int read(int &in) {
	in=0;int f=1;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())
		if(ch=='-') f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())
		in=in*10+ch-'0';
	return in*f;
}

inline void add_edge(int x,int y) {
	to[++cnt]=y;nxt[cnt]=head[x];head[x]=cnt;
}

inline void tarjan(int x) {
	low[x]=dfn[x]=++tt;vis[x]=1;zhan[++sum]=x;
	int y;
	for(int i=head[x];i;i=nxt[i]) {
		y=to[i];
		if(!dfn[y]) {
			tarjan(y);low[x]=Min(low[x],low[y]);
		}else if(vis[y])
			low[x]=Min(low[x],dfn[y]);
	}
	if(low[x]==dfn[x]) {
		tot++; do{
			y=zhan[sum--];vis[y]=0;
			w2[tot]+=w[y];v2[tot]+=v[y];fr[y]=tot;
		}while(y!=x);
	}
}

inline void dfs(int x) {
	for(int i=0;i<p[x].size();i++) {
		int y=p[x][i];dfs(y);
		for(int j=m-v2[x];j>=0;j--) {
			for(int k=0;k<=j;k++)
				f[x][j]=Max(f[x][j],f[x][k]+f[y][j-k]);
		}
	}

	for(int i=m;i>=0;i--) {
		if(i>=v2[x]) f[x][i]=f[x][i-v2[x]]+w2[x];
		else f[x][i]=0;
	}
}

int main() {
	read(n);read(m);
	for(int i=1;i<=n;i++) read(v[i]);
	for(int i=1;i<=n;i++) read(w[i]);
	for(int i=1;i<=n;i++) {
		int x;read(x);if(x!=0)add_edge(i,x);
	}
	for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
	for(int i=1;i<=n;i++) {
		for(int j=head[i];j;j=nxt[j]) {
			if(fr[i]!=fr[to[j]]) p[fr[to[j]]].push_back(fr[i]),ru[fr[i]]++;
		}
	}
	int ans=tot+1;
	for(int i=1;i<=tot;i++) if(!ru[i]) p[ans].push_back(i);
	dfs(ans);printf("%d\n",f[ans][m]);
	return 0;
}
