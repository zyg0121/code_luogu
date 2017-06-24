#include <cstdio>
#include <cstring>
#include <algorithm>

typedef long long LL;

LL ans,n,k,p,q;

inline LL read() {
	LL in=0;char ch=getchar();
	for(;ch>='0'&&ch<='9';ch=getchar())
		in=in*10+ch-'0';
	return in;
}

int main() {
	n=read();k=read();
	for(LL i=1; i<=n; i++) {
		p=k/i,q=k%i;
		LL j=p?k/p:n;
		if(j>n)j=n;
		ans+=q*(j-i+1)-(j-i+1)*(j-i)/2*p;
		i=j;
    }
	printf("%lld\n",ans);
	return 0;
}
