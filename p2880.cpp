#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int size =1e5+10;
int a[size];
int f_max[size][40];
int f_min[size][40];

void init_rmq_min(int m) {
	for(int i=1;i<=m;i++) 
		f_min[i][0]=a[i];
	for(int j=1;(1<<j)<m;j++) {
		for(int i=1;i<=m;i++) {
			if(i+(1<<j)-1 <= m) {
				f_min[i][j]=min(f_min[i][j-1],f_min[i+(1<<(j-1))][j-1]);
			}
		}
	}
}

int query_rmq_min(int l,int r) {
	int i=0;
	for(;(1<<i)+l-1<=r;i++){};
	i--;
	return min(f_min[l][i],f_min[r-(1<<i)+1][i]);
}

void init_rmq_max(int m) {
	for(int i=1;i<=m;i++) 
		f_max[i][0]=a[i];
	for(int j=1;(1<<j)<m;j++) {
		for(int i=1;i<=m;i++) {
			if(i+(1<<j)-1 <= m) {
				f_max[i][j]=max(f_max[i][j-1],f_max[i+(1<<(j-1))][j-1]);
			}
		}
	}
}

int query_rmq_max(int l,int r) {
	int i=0;
	for(;(1<<i)+l-1<=r;i++){};
	i--;
	return max(f_max[l][i],f_max[r-(1<<i)+1][i]);
}

int main() {
	int m,n;
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++) 
		scanf("%d",&a[i]);
	init_rmq_min(m);
	init_rmq_max(m);
	for(int i=1,l,r;i<=n;i++) {
		scanf("%d%d",&l,&r);
		printf("%d\n",query_rmq_max(l,r)-query_rmq_min(l,r));
	}
	return 0;
}
