#include <cstdio>
#include <cstring>
using namespace std;

long long ans,tot=1;
int n,k;

int main( ) {
	scanf("%d%d",&k,&n);
	while(n) {
		ans+=n%2*tot;
		n/=2;
		tot*=k;
	}
	printf("%lld\n",ans);
	return 0;
}
