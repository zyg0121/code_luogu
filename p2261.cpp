#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long LL;
LL n,k,ans=0;
LL i,j;

int main ()
{
    scanf("%d%d",&n,&k);
    for (i=2 ; (double)k/i>=floor(sqrt(k)) && n>k/i ; i++)
        ans+=(min(k/(i-1),n)-k/i)*(k%min(n,k/(i-1))+k%(k/i+1))/2;
    if (n>k)
        ans+=k*(n-k);
    for (j=1 ; j<=floor(k/(i-1)) && j<=n ; j++)
        ans+=k%j;
    printf("%lld\n",ans);
    return 0;
} 
