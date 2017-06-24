#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

const int size = 1000+10;
typedef long long LL;
LL num[size];
LL gcdnum[size][size];
LL n,m;

inline LL gcd(LL x,LL y)
{
    LL i,j;
    if(x==0) return y;
    if(y==0) return x;
    for(i=0;(x&1)==0;i++) x>>=1;
    for(j=0;(y&1)==0;j++) y>>=1;
    if(j<i) i=j;
    while(1) {
        if(x<y) x^=y,y^=x,x^=y;
        if((x-=y)==0) return y<<i;
        while((x&1)==0) x>>=1;
    }
}

int main() {
	scanf("%lld%lld",&n,&m);
	for(int i=0;i<n;i++) 
		scanf("%d",&num[i]);
	for(int i=0;i<n;i++) {
		gcdnum[i][i]=num[i];
		for(int j=i+1;j<n;j++)
			gcdnum[i][j]=gcd(gcdnum[i][j-1],num[j]);
	}
	for(int i=0;i<m;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%lld\n",a<=b ? gcdnum[a-1][b-1] : gcdnum[b-1][a-1]);
	}
	return 0;
}
