#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;

LL n,mod;

LL mul (LL a,LL b) {
	LL ret=0;
	for(;b;b>>=1,a=(a+a)%mod)
		if(b&1)
			ret=(ret+a)%mod;
	return ret;
}

struct matrix {
    LL a[3][3];
    matrix operator * (const matrix &b) const {
        matrix tmp;
        for(LL i=1;i<=n;i++) 
            for(LL j=1;j<=n;j++) {
                tmp.a[i][j] = 0;
                for(LL k=1;k<=n;k++) {
                    tmp.a[i][j] = (tmp.a[i][j]+a[i][k]*b.a[k][j])%mod;
                }
            }
        return tmp;
    }
    matrix operator ^(LL n) {
    	matrix a,b;
    	a=b=*this;
    	for(n--;n;n>>=1,b=b*b)
    		if(n&1)
    			a=a*b;
    	return a;
    }
}f;

int main() {
	scanf("%lld%lld",&n,&mod);
	f.a[2][0]=1;
	for(LL i=10;;i*=10) {
		matrix tmp;
		tmp.a[0][0]=i;
		tmp.a[0][1]=tmp.a[0][2]=tmp.a[1][1]=tmp.a[1][2]=tmp.a[2][2]=1;
		if(i>n){
			f=f*(tmp^(n-i/10+1));
			break;
		}
		f=f*(tmp^(i-i/10));
	}
	printf("%lld\n",f.a[0][0]);
	return 0;
}
