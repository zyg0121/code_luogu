#include "cstdio"
using namespace std;

const int size = 5e6+10;
int n,m,tree[size];

int lowbit(int k) {
	return k&-k;
}

void keep(int k,int num) {
	while(k<=n) {
		tree[k]+=num;
		k+=lowbit(k);
	}
}

int count(int k) {
	int ans=0;
	while(k) {
		ans+=tree[k];
		k-=lowbit(k);
	}
	return ans;
}

int main() {
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) {
		int op;
		scanf("%d",&op);
		keep(i,op);ss
	}
	for(int i=1;i<=m;i++) {
		int p,u,v;
		scanf("%d%d%d",&p,&u,&v);
		if(p==1)
			keep(u,v);
		else 
			printf("%d\n",count(v)-count(u-1));
	}
	return 0;
}
