#include <cstdio>
#include <cstring>
#include <algorithm>

const int size = 25000+10;
typedef long long LL;
LL ans,n,x,y;
LL a[size],b[size];
int main() {
    scanf("%lld%lld%lld",&n,&x,&y);
    for(int i=1;i<=n;i++)
	scanf("%lld%lld",&a[i],&b[i]);
    std::sort(a+1,a+n+1);
    std::sort(b+1,b+n+1);
    for(int i=1;i<=n;i++) {
	if(a[i]<b[i])
	    ans+=(b[i]-a[i])*x;
	else
	    ans+=(a[i]-b[i])*y;
    }
    printf("%lld\n",ans);
    return 0;
}
