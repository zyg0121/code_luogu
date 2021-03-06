#include <cstdio>
#include <cstring>
#include <algorithm>

const int size = 100+10;
const int H=50000,p=5000,INF=1<<30;

int c[size],w[size],f[H+p];
int n,h;

int main() {
    for (int i=1;i<=H+p;++i)
        f[i]=INF;
    scanf("%d%d",&n,&h);
    for(int i=1;i<=n;i++)
	scanf("%d%d",&c[i],&w[i]);
    for(int i=1;i<=n;i++)
	for(int v=c[i];v<=h+p;v++)
	    f[v]=std::min(f[v],f[v-c[i]]+w[i]);
    int ans=INF;
    for(int i=h;i<=h+p;i++)
	ans=std::min(ans,f[i]);
    printf("%d\n",ans);
}
