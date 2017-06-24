#include "cstdio"
#include "algorithm"
using namespace std;

#define lson l,m,rt<<1 
#define rson m+1,r,rt<<1 | 1 

const int size = 2e5+10;
int maxx[size<<2];
int A[size<<2];

void pushup(int rt) {
    maxx[rt]=max(maxx[rt<<1],maxx[rt<<1|1]);
}

void build(int l,int r,int rt) {
    if(l==r) {
        scanf("%d",&maxx[rt]);
        A[l]=maxx[rt;
        return ;
    }
    int m = (l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}

void update(int p,int sc,int l,int r,int rt) {
    if(l==r) {
        maxx[rt]=sc;
        return ;
    }
    int m=(l+r)>>1;
    if(p<=m)
        update(p,sc,lson);
    else
        update(p,sc,rson);
    pushup(rt);
}

int query(int L,int R,int l,int r,int rt) {
    if(L<=l && r<=R) {
        return maxx[rt];
    }
    int m=(r+l)>>1;
    int ret=0;
    if(L<=m)
        ret = max(ret,query(L,R,lson));
    if(R>m)
        ret = max(ret,query(L,R,rson));
    return ret;
}

int main() {
    int n,m;
    while(~scanf("%d%d",&n,&m)) {
        build(1,n,1);
        while(m--) {
            char op[2];
            int a,b;
            scanf("%s%d%d",op,&a,&b);
            if(op[0] == 'Q')
                printf("%d\n",query(a,b,1,n,1));
            else if(op[0] == 'U')
            {
            	if(A[a]<b){
            		A[a]=b;
            		update(a,b,1,n,1);
            	}  
            } 
        }
    }
    return 0;
}
