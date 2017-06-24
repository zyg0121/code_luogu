#include <cstdio>
#include <algorithm>

typedef long long LL;
const int maxm=1e6+10;

int A[maxm],f[maxm];
int ave,mid,n;
LL tot,ans;

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
	scanf("%d",&A[i]),tot+=A[i];
    ave=tot/n;
    for(int i=2;i<=n;i++)
	f[i]=f[i-1]+A[i]-ave;
    std::sort(f+1,f+n+1);
    mid=f[n/2];
    for(int i=1;i<=n;i++)
	ans+=abs(mid-f[i]);
    printf("%lld\n",ans);
    return 0;
}
