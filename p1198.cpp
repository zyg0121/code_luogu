#include "cstdio"
#include "iostream"
#include "cstring"
#include "algorithm"
using namespace std;

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
typedef long long LL;
const int size = 2e6+10;
const int n = size-1;
const int INF = 2147283467;

int sum[size<<2];
int t,d,m,len;

void build(int l,int r,int rt)
{
    sum[rt]=-INF;
    if (l==r)return;
    int mid=(l+r)>>1;
    build(lson);build(rson);
}

void update(int L,int R,int l,int r,int rt) {
	if(l==r) {
		sum[rt]=R;
		return;
	}
	int mid =(l+r)>>1;
	if(L<=mid) 
		update(L,R,lson);
	else 
		update(L,R,rson);
	sum[rt]=max(sum[rt<<1],sum[rt<<1|1]);
}

int query(int L,int R,int l,int r,int rt) {
	if(L<=l && r<=R ) 
		return sum[rt];
	int mid=(l+r)>>1;
	int ans=-INF;
	if(L<=mid) 
		ans=query(L,R,lson);
	if(R>mid) 
		ans=max(ans,query(L,R,rson));
	return ans;
}

int main() {
	scanf ("%d%d",&m,&d);
    build(1,n,1);
    for (int b=1;b<=m;++b)
    {
        char c;int i;
        cin >>c;scanf ("%d",&i);
        if (c=='A') {
        	len++;
        	update(len,(i+t)%d,1,n,1);
        }
        else {
        	t=query(len-i+1,len,1,n,1);
        	printf ("%d\n",t);
        }
    }
    return 0;
}	
