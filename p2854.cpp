#include <cstdio>
#include <cstring>
#include <algorithm>

const int size = 1e6+10;
const int maxx = 1e3+10;

struct node {
    int st,end;
    int len,f,w;
    bool operator < (const node &A) const {
	return st<A.st;
    }
}r[size];

int f[maxx][maxx];
int l,n,m,x,ans=-1;

int main() {
    memset(f,-1,sizeof(f));
    f[0][0]=0;
    scanf("%d%d%d",&l,&n,&m);
    for(int i=1;i<=n;i++) {
	scanf("%d%d%d%d",&r[i].st,&r[i].len,&r[i].f,&r[i].w);
	r[i].end=r[i].st+r[i].len;
    }
    std::sort(r+1,r+n+1);
    for(int i=1;i<=n;i++)
	for(int j=m;j>=r[i].w;j--)
	    if(f[j-r[i].w][r[i].st]>=0)
		f[j][r[i].end]=std::max(f[j][r[i].end],f[j-r[i].w][r[i].st]+r[i].f);
    for(int v=m;v>=0;v--) ans=std::max(ans,f[v][l]);
    printf("%d\n",ans);
    return 0;
}
