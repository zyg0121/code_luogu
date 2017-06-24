#include<cstdio>
using namespace std;

typedef long long LL;
const int mod = 100003;

LL n,m;

LL Pow(LL a,LL b) {
    LL res=1;
    for(;b;b>>=1,(a*=a)%=mod)
	if(b&1) (res*=a)%=mod;
    return res;
}

int main(){
    scanf("%lld%lld",&m,&n);
    printf("%lld\n",(Pow( m,n )-m*Pow( m-1,n-1 )%mod+mod)%mod);
    return 0;
}
