#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int sizen=2e5,sizem=5e5;
struct node {
	int x,y,z;
}v[sizem];
int n,m,q;
int u[sizen],f[sizen],p[sizen],d[sizen][20];
int deep[sizen];

bool cmp(node a,node b) {
	return a.z>b.z;
}

int find(int x) {
	return u[x]==x ? x : u[x]=find(u[x]);
}

int Lca(int x,int y) {
	int t,i=0;
	if(deep[x]<deep[y]) 
     	swap(x,y);
	while(i>=0) {
		while(deep[d[x][i]]>=deep[y]) {
			x=d[x][i];i++;
		}
		i--;
	}
	i=0;
	while(f[x]!=f[y]) {
		while(d[x][i]!=d[y][i]) {
			x=d[x][i];y=d[y][i];i++;
		}
		i--;
	}
	return f[x];
}

int main() {
	scanf("%d%d",&n,&m);
	int w=n,tot=0,k,x,y;
	for(int i=1;i<=m;i++) 
		scanf("%d%d%d",&v[i].x,&v[i].y,&v[i].z);
	sort(v+1,v+m+1,cmp);
	for(int i=1;i<=n;i++) 
		u[i]=i;
	for(int i=1;i<=m;i++) {
		int bx = find(v[i].x);
		int by = find(v[i].y);
		if(bx!=by) {
			u[by]=u[bx]=f[bx]=f[by]=++w;
			f[w]=0;p[w]=v[i].z;u[w]=w;
			if(++tot==n-1) break;
		}
	}
	n=w;
	deep[n]=0;
	for(int i=n-1;i;i--) {
		deep[i]=deep[f[i]]+1;
		d[i][0]=f[i];
		k=0;
		while(d[d[i][k]][k]) {
			d[i][k+1]=d[d[i][k]][k];
			k++;
		}
	}
	scanf("%d",&q);
	while(q--) {
		scanf("%d%d",&x,&y);
		if(find(x)==find(y))
			printf("%d\n",p[Lca(x,y)]);
		else
			puts("-1");
	}
	return 0;
}
			
