#include <cstdio>
#include <cstring>
#include <algorithm>

const int size = 1000100;
typedef long long LL;

LL a[size],b[size],num[size];
LL k,p,n;

int main() {
    scanf("%lld%lld",&n,&p);
    for(int i=1;i<=n;i++)
        scanf("%lld",&num[i]);
    b[1]=num[1];
    for(LL i=1;i<=n;i++) {
        k+=num[i];b[i]=k;
        if(k<0) k=0;
    }
    for(LL i=2;i<=n;i++)
        if(b[i]<b[i-1]) b[i]=b[i-1];
    a[1]=b[1];
    a[2]=a[1]+b[1];
    bool flag=false;
    for(LL i=3;i<=n;i++) {
        a[i]=a[i-1];if(b[i-1]>0) a[i]+=b[i-1];
        if(a[i]>b[1]) flag=true;
        if(flag==true) a[i]%=p;
    }
    if(flag==true) printf("%lld\n",a[n]);
    else printf("%lld\n",b[1]);
    return 0;
}
