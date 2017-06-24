#include "cstdio"
#include "algorithm"
#include "iostream"
using namespace std;

#define M 500005
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

int sum[M<<2];

inline void PushPlus(int rt)
{
	sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}

void build(int l, int r, int rt)
{
	if(l == r)
	{
		scanf("%d", &sum[rt]);
		return ;
	}
	int m = ( l + r )>>1;

	build(lson);
	build(rson);
	PushPlus(rt);
}

void Updata(int p, int add, int l, int r, int rt)
{

	if( l == r )
	{
		sum[rt] += add;
		return ;
	}
	int m = ( l + r ) >> 1;
	if(p <= m)
		Updata(p, add, lson);
	else
		Updata(p, add, rson);
	PushPlus(rt);
}

int query(int L,int R,int l,int r,int rt)
{
	if( L <= l && r <= R )
	{
		return sum[rt];
	}
	int m = ( l + r ) >> 1;
	int ans=0;
	if(L<=m )
		ans+=query(L,R,lson);
	if(R>m)
		ans+=query(L,R,rson);
	return ans;
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
            printf("%d\n",query(a,b,1,N,1));
        }
        else {
            scanf("%d%d",&a,&b);
            Updata(a,b,1,N,1);
        }
    }
    return 0;
}
