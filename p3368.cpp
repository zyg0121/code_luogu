#include "cstdio"
#include "cstring"
using namespace std;

const int size = 5e6+10;
int n,m,tree[size];

int lowbit(int k) {
	return k&-k;
}

void add(int from,int add_num) {
	while(from<=n) {
		tree[from]+=add_num;
		from+=lowbit(from);
	}
}

int sum(int from) {
	int ans=0;
	while(from) {
		ans+=tree[from];
		from-=lowbit(from);
	}
	return ans;
}

int main() {
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) {
		int op;
		scanf("%d",&op);
		add(i,op);add(i+1,-op);
	}
	for(int i=1;i<=m;i++) {
		int p,l,r,op;
		scanf("%d",&p);
		if(p==1) {
			scanf("%d%d%d",&l,&r,&op);
			add(l,op);add(r+1,-op);
		}
		else {
			scanf("%d",&op);
			printf("%d\n",sum(op));
		}
	}
	return 0;
}
