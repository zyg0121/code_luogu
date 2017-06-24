#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;

LL m=1,x,n,y,ans,m1;
LL a[20],b[20];

void ex_gcd(LL a,LL b,LL &x,LL &y) {
	if(!b) {
		x=1;y=0;
	}
	else {
		ex_gcd(b,a%b,y,x);
		y-=(a/b)*x;
	}
}

int main() {
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) {
		scanf("%lld%lld",&a[i],&b[i]);
		m*=a[i];
	}
	for(int i=1;i<=n;i++) {
		x=0;y=0;
		m1=m/a[i];
		ex_gcd(m1,a[i],x,y);
		ans+=(b[i]*m1*x)%m;
	}
	printf("%lld\n",((ans%m)+m)%m);
	return 0;
}
