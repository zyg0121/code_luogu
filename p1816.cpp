#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int size =1e5+10;
int a[size];
int f[size][40];

void init_rmq(int m) {
	for(int i=1;i<=m;i++) 
		f[i][0]=a[i];
	for(int j=1;(1<<j)<m;j++) {
		for(int i=1;i<=m;i++) {
			if(i+(1<<j)-1 <= m) {
				f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
			}
		}
	}
}

int query_rmq(int l,int r) {
	int i=0;
	for(;(1<<i)+l-1<=r;i++){};
	i--;
	return min(f[l][i],f[r-(1<<i)+1][i]);
}

int main() {
	int m,n;
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++) 
		scanf("%d",&a[i]);
	init_rmq(m);
	for(int i=1,l,r;i<=n;i++) {
		scanf("%d%d",&l,&r);
		printf("%d ",query_rmq(l,r));
	}
	return 0;
}
