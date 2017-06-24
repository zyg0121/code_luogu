#include<cstdio>
#include<cstring>

#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)<(b)?(b):(a))

const int size=1000005,INF=0x3f3f3f3f;
int n,k,a[size],maxx[size],minn[size];

void update(int x,int c) {
	for(;x<=n;x+=x&-x) {
		maxx[x]=Max(c,maxx[x]);
		minn[x]=Min(c,minn[x]);
	}
}

inline int query_max(int l,int r) {
	int ans=-INF;
	while(l<=r) {
		ans=Max(ans,a[r]);
		for(--r;r-l>=(r&-r);r-=r&-r)
			ans=Max(ans,maxx[r]);
	}
	return ans;
}

inline int query_min(int l,int r) {
	int ans=INF;
	while(l<=r) {
		ans=Min(ans,a[r]);
		for(--r;r-l>=(r&-r);r-=r&-r)
			ans=Min(ans,minn[r]);
	}
	return ans;
}

int main() {
	scanf("%d%d",&n,&k);
	memset(minn,0x3f,sizeof minn);
	memset(maxx,-0x3f,sizeof maxx);
	for(int i=1;i<=n;i++) 
		scanf("%d",&a[i]),update(i,a[i]);
	for(int i=1;i<=n-k+1;i++)
		printf("%d ",query_min(i,i+k-1));
	puts("");
	for(int i=1;i<=n-k+1;i++)
		printf("%d ",query_max(i,i+k-1));
	return 0;
}
