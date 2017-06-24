#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

typedef long long LL;
LL m,n;
LL ans=1;
const int mod = 6662333;

int main() {
	scanf("%lld",&n);
	m=2;n=n-1;
	for(;n;n>>=1,m=(long long)m*m%mod)
        if(n&1)
            ans=(long long)ans*m%mod;
    printf("%lld",ans);
	return 0;
}
