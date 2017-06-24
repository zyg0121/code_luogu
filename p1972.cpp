#include <cstdio>
#include <algorithm>

using namespace std;

const int maxx = 5e5 + 100;
const int maxn = 1e7 + 100;
const int maxm = 2e6 + 100;

int n,m,tot;
int a[maxx],t[maxx],next[maxx];
int head[maxn];

struct Que{
    int l,r,id,ans;
}Q[maxm];

int lowbit(int x){
    return x&(-x);
}

void Add(int x,int k){
    for(int i=x;i<=n;i+=lowbit(i))
        t[i] += k;
}

int Query(int x){
    int tmp = 0;
    for(int i=x;i>=1;i-=lowbit(i))
        tmp += t[i];
    return tmp;
}

bool cmp1(Que a,Que b){
    return a.l==b.l? a.r<b.r : a.l<b.l;
}

bool cmp2(Que a,Que b){
    return a.id<b.id;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),a[i]++,tot=max(tot,a[i]);
    for(int i=n;i>=1;i--)
        next[i]=head[a[i]],head[a[i]]=i;
    for(int i=1;i<=tot;i++)
        if(head[i]) Add(head[i],1);
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
        scanf("%d%d",&Q[i].l,&Q[i].r),Q[i].id=i;
    sort(Q+1,Q+m+1,cmp1);
    int now=1;
    for(int i=1;i<=m;i++){
        while(now<Q[i].l){
            if(next[now])
                Add(next[now],1);
            now++;
        }
        Q[i].ans=Query(Q[i].r)-Query(Q[i].l-1);
    }
    sort(Q+1,Q+m+1,cmp2);
    for(int i=1;i<=m;i++)
        printf("%d\n",Q[i].ans);
    return 0;
}
