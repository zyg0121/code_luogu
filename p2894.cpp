#include <cstdio>
#include <cstring>
#include <algorithm>

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define Max(a,b) ((a)>(b)?(a):(b))

const int size = 50000+10;
int left[size<<2],right[size<<2],lsum[size<<2],rsum[size<<2];
int sum[size<<2],cover[size<<2];
int n,m,pos,opt;

void build(int l,int r,int rt) {
	left[rt]=l;right[rt]=r;cover[rt]=-1;
	sum[rt]=lsum[rt]=rsum[rt]=r-l+1;
	int m=(l+r)>>1;
	build(lson);build(rson);
}

void pushup(int rt) {
	int l=left[rt],r=right[rt];
	lsum[rt]=lsum[rt<<1];rsum[rt]=rsum[rt<<1|1];
	int m=(l+r)>>1;
	if(lsum[rt]==m-l+1) lsum[rt]+=lsum[rt<<1|1];
	if(rsum[rt]==r-m) rsum[rt]+=rsum[rt<<1];
	sum[rt]=Max(Max(sum[rt<<1],sum[rt<<1|1]),lsum[rt<<1|1]+rsum[rt<<1]);
}

void pushdown(int rt){
    if(cover[rt]!=-1){
        cover[rt<<1]=cover[rt<<1|1]=cover[rt];
        sum[rt<<1]=lsum[rt<<1]=rsum[rt<<1]=cover[rt]?0:right[rt<<1]-left[rt<<1]+1;
        sum[rt<<1|1]=lsum[rt<<1|1]=rsum[rt<<1|1]=cover[rt]?0:right[rt<<1|1]-left[rt<<1|1]+1;
        cover[rt]=-1;
    }
}

void update(int l,int r,int rt,int c) {
	if(left[rt]>=l and right[rt]<=r) {
		sum[rt]=lsum[rt]=rsum[rt]=c?0:right[rt]-left[rt]+1;
		cover[rt]=c;return ;
	}
	if(left[rt]>r or right[rt]<l) return ;
	pushdown(rt);
	update(l,r,rt<<1,c);update(l,r,rt<<1|1,c);
	pushup(rt);
}

int Query(int rt,int c) {
	if(left[rt]==right[rt]) 
		return left[rt];
	pushdown(rt);
	int m=(left[rt]+right[rt])>>1;
	if(sum[rt<<1]>=c) return Query(rt<<1,c);
	else if(rsum[rt<<1]+lsum[rt<<1|1]>=c) return m-rsum[rt<<1]+1;
	else return Query(rt<<1|1,c);
}

int main() {
	scanf("%d%d",&n,&m);
	build(1,n,1);
	while(m--) {
		int x,y;
		scanf("%d",&opt);
		if(opt==1) {
			scanf("%d",&x);
			if(sum[1]<x) puts("0");
			else {
				printf("%d\n",pos=Query(1,x));
				update(pos,pos+x-1,1,1);
			}
		}
		else {
			scanf("%d%d",&x,&y);
			update(x,x+y-1,1,0);
		}
	}
	return 0;
}
