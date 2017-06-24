#include "iostream"
#include "cstdio"
#include "cstring"
using namespace std;

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
typedef long long LL;
const int size=1e6+10;
LL sum[size<<2],Add[size<<2],flag[size<<2];
LL A[size];
int n,m,n1,x1,y1,k1,Mod;

void Pushup(int rt) {
	sum[rt]=(sum[rt<<1]+sum[rt<<1|1]);
}

void build(int l,int r,int rt) {
    if(l==r) {
        sum[rt]=A[l]%Mod;
        return ;
    }
    int m=(l+r)>>1;
    flag[rt]=1;
    build(lson);
    build(rson);
    Pushup(rt);
}

void Pushdown(int rt,int ln,int rn) {
    sum[rt<<1]=sum[rt<<1]*flag[rt]%Mod+Add[rt]*ln%Mod;
    flag[rt<<1]=(flag[rt<<1]*flag[rt])%Mod;
    Add[rt<<1]=Add[rt<<1]*flag[rt]%Mod+Add[rt]%Mod;
    sum[rt<<1|1]=(sum[rt<<1|1]*flag[rt])%Mod+(Add[rt]*rn)%Mod;
    Add[(rt<<1)|1]=(Add[rt<<1|1]*flag[rt])%Mod+Add[rt]%Mod;
    flag[rt<<1|1]=(flag[rt<<1|1]*flag[rt])%Mod;
    Add[rt]=0;
    flag[rt]=1;
}

void updata_1(int L,int R,int C,int l,int r,int rt) {
    if(L<=l&&R>=r) {
        Add[rt]=(Add[rt]+C)%Mod;
        sum[rt]=(sum[rt]+C*(r-l+1))%Mod;
        return ;
    }
    int m=(l+r)>>1;
    Pushdown(rt,m-l+1,r-m);
    if(L<=m)    
    	updata_1(L,R,C,lson);
    if(R>m)    
    	updata_1(L,R,C,rson);
    Pushup(rt);
}

void updata_2(int L,int R,int C,int l,int r,int rt) {
    if(L<=l&&R>=r) {
        flag[rt]=(flag[rt]*C)%Mod;
        Add[rt]=(Add[rt]*C)%Mod;
        sum[rt]=(sum[rt]*C)%Mod;
        return ;
    }
    int m=(l+r)>>1;
    Pushdown(rt,m-l+1,r-m);
    if(L<=m)    updata_2(L,R,C,lson);
    if(R>m)    updata_2(L,R,C,rson);
    Pushup(rt);
}

LL Query(int L,int R,int l,int r,int rt) {
    if(L<=l&&R>=r) {
        return sum[rt]%Mod;
    }
    int m=(l+r)>>1;
    Pushdown(rt,m-l+1,r-m);
    LL ans=0;
    if(L<=m)    ans+=Query(L,R,lson);
    if(R>m)    ans+=Query(L,R,rson);
    return ans%Mod;
}

int main() {
    scanf("%d%d%d",&n,&m,&Mod);
    for(int i=1;i<=n;i++)
        scanf("%lld",&A[i]);
    build(1,n,1);
    for(int i=1;i<=m;i++) {
        scanf("%d",&n1);
        if(n1==1) {
            scanf("%d%d%d",&x1,&y1,&k1);
            updata_2(x1,y1,k1,1,n,1);
        }
        else if(n1==2) {
            scanf("%d%d%d",&x1,&y1,&k1);
            updata_1(x1,y1,k1,1,n,1);
        }
        else {
            scanf("%d%d",&x1,&y1);
            printf("%lld\n",Query(x1,y1,1,n,1)%Mod);
        }
    }
    return 0;
}
