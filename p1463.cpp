#include<cstdio>
#include<cmath>
using namespace std;
typedef long long LL;
LL n,maxx,ans;
LL num[12]={0,2,3,5,7,11,13,17,19,21,23};
void findd(LL now,LL tot,LL u,LL v) {
    if(maxx<tot || (tot==maxx && ans>now)) {
        maxx=tot;ans=now;
    }
    if(v>=11)
        return;
    for(LL i=1;i<=u;i++)
    {
        now*=num[v];
        if(now>n) 
            return;
        findd(now,tot*(1+i),i,v+1);
    }
}

int main() {
    scanf("%lld",&n);
    findd(1,1,500,1);
    printf("%lld",ans);
    return 0;
}
