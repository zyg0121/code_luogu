#include <cstdio>
#include <cstring>
#include <algorithm>

const int size = 100000+10;
typedef long long LL;

struct node {
	LL p,c;
}t[size];

bool cmp(const node &a,const node &b) {
	return a.p<b.p;
}

int n;
LL b,ans;

int main() {
	scanf("%d%lld",&n,&b);
	for(int i=1;i<=n;i++) 
		scanf("%lld%lld",&t[i].p,&t[i].c);
	std::sort(t+1,t+n+1,cmp);
	for(int i=1;i<=n;i++) {
		LL k=b/t[i].p;
		if(k>t[i].c) {
			b-=t[i].c*t[i].p;
			ans+=t[i].c;
		}
		else {
			ans+=k;break;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
