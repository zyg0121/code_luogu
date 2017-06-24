#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
typedef long long LL;
using namespace std;

const LL mod = 1000000007;
LL n,k;

struct matrix {
	LL a[105][105];
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
}a;

inline LL read() {
	LL in=0,f=1;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())
		if(ch=='-') 
			f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())
		in=in*10+ch-'0';
	return in*f;
}

matrix quickpow(matrix a,LL x) {
	matrix ret,k;
	k=a;ret=a;x--;
	for(;x;x>>=1,k=k*k)
		if(x&1)
			ret=ret*k;
	return ret;
}

int main() {
	n=read();k=read();
	for(LL i=1;i<=n;i++) 
		for(LL j=1;j<=n;j++) 
			a.a[i][j]=read();
	a=quickpow(a,k);
	for(LL i=1;i<=n;i++) {
		for(LL j=1;j<=n;j++) 
			printf("%lld ",a.a[i][j]);
		puts("");
	}
	return 0;
}
