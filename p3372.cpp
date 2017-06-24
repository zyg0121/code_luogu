#include "cstdio"
#include "algorithm"
#include "iostream"
using namespace std;

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
typedef long long LL;
const int size = 1e5+10;
LL add[size<<2],sum[size<<2];

void pushup(int rt) {
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}

void pushdown(int rt,int m) {
    if(add[rt]) {
        add[rt<<1]+=add[rt];
        add[rt<<1|1]+=add[rt];
        sum[rt<<1]+=add[rt]*(m-(m>>1));
        sum[rt<<1|1]+=add[rt]*(m>>1);
        add[rt]=0;
    }
}

void build(int l,int r,int rt) {
    add[rt]=0;
    if(l == r) {
        scanf("%lld",&sum[rt]);
        return;
    }
    int m=(r+l)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}

void update(int L,int R,int c,int l,int r,int rt) {
    if(L <= l && r<=R) {
        add[rt]+=c;
        sum[rt]+=(LL)c*(r-l+1);
        return ;
    }
    pushdown(rt,r-l+1);
    int m=(l+r)>>1;
    if(L<=m) update(L,R,c,lson);
    if(m<R) update(L,R,c,rson);
    pushup(rt);
}

LL query (int L,int R,int l,int r,int rt) {
    if(L<=l and r<=R) {
        return sum[rt];
    }
    pushdown(rt,r-l+1);
    int m=(l+r)>>1;
    LL ret=0;
    if(L<=m) ret+=query(L,R,lson);
    if(m<R) ret+=query(L,R,rson);
    return ret;
}

int main()
{
    int N,Q;
    scanf("%d%d",&N,&Q);
    build(1,N,1);
    while(Q--) {
        int p;
        int a,b,c;
        scanf("%d",&p);
        if(p==2) {
            scanf("%d%d",&a,&b);
            printf("%lld\n",query(a,b,1,N,1));
        }
        else {
            scanf("%d%d%d",&a,&b,&c);
            update(a,b,c,1,N,1);
        }
    }
    return 0;
}
