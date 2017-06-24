#include <cstdio>
#include <cstring>
#include <algorithm>

const int size = 30000+30;
const int inf = 0x3f3f3f3f;

int f[size],N;

int main () {
	int n;scanf("%d",&n);
	N=n*5;
	memset(f,inf,sizeof f);f[0]=0;
	while(n--) {
		int a,b,c;scanf("%d%d%d",&a,&b,&c);
		for(int i=N;i>=0;i--) {
			int tmp=f[i];f[i]=inf;
			if(a and i-a>=0) f[i]=std::min(f[i],f[i-a]);
			if(b) f[i]=std::min(tmp+b,f[i]);
			if(c and i-c>=0) f[i]=std::min(f[i-c]+c,f[i]);
		}
	}
	int ans=inf;
	for(int i=0;i<=N;i++)
		ans=std::min(ans,std::max(i,f[i]));
	printf("%d\n",ans);
	return 0;
}
