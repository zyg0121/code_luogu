#include <cstdio>
#include <cstring>
#include <algorithm>

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
typedef long long LL;

const int size = 100000+10;
bool color[size<<2][31],query[31];
int lz[size<<2],sum[size<<2];
int n,m,t;

void build(int l,int r,int rt) {
	sum[rt]=1;color[rt][1]=true;
	if(l==r) return ;
	int m=(l+r)>>1;
	build(lson);build(rson);
}

void pushup(int rt) {
	sum[rt]=0;
	for(int i=1;i<=t;i++) {
		color[rt][i]=false;
		if(color[rt<<1][i] or color[rt<<1|1][i]) {
			color[rt][i]=true;sum[rt]++;
		}
	}
}

void pushdown(int rt) {
	lz[rt<<1]=lz[rt<<1|1]=lz[rt];
	for(int i=1;i<=t;i++) color[rt<<1][i]=false;
	color[rt<<1][lz[rt]]=true;sum[rt<<1]=1;
	for(int i=1;i<=t;i++) color[rt<<1|1][i]=false;
	color[rt<<1|1][lz[rt]]=true;sum[rt<<1|1]=1;
	lz[rt]=0;
}

void update(int l,int r,int rt,int L,int R,int k) {
	if(L<=l and r<=R) {
		lz[rt]=k;
		for(int i=1;i<=t;i++) color[rt][i]=false;
		color[rt][k]=true;sum[rt]=1;return ;
	}
	if(lz[rt]) pushdown(rt);
	int m=(l+r)>>1;
	if(L<=m) update(lson,L,R,k);
	if(m<R) update(rson,L,R,k);
	pushup(rt);
}

void Query(int l,int r,int rt,int L,int R) {
	if(L<=l and r<=R) {
		for(int i=1;i<=t;i++) if(color[rt][i]) query[i]=true;
		return ;
	}
	if(lz[rt]) pushdown(rt);
	int m=(l+r)>>1;
	if(L<=m) Query(lson,L,R);
	if(m<R) Query(rson,L,R);
}

int main()
{
    scanf ("%d%d%d",&n,&t,&m);
    build(1,n,1);
    for (int i=1;i<=m;i++) {
        char ch[100];
        int a,b,k;
        scanf("%s",ch);
        if (ch[0]=='C') {
            scanf ("%d%d%d",&a,&b,&k);
            if (a>b) std::swap(a,b);
            update(1,n,1,a,b,k);
        }
        else {
            scanf ("%d%d",&a,&b);
            if (a>b) std::swap(a,b);
            Query(1,n,1,a,b);
            int ans=0;
            for (int i=1;i<=t;i++) {
            	ans+=query[i];query[i]=0;
            }
            printf ("%d\n",ans);
        }
    }
    return 0;
}
