#include<iostream>
#include<cstdio>
#include<cstring>

const int size = 1000+10;

int a[size],s[5],p[5];
int k,m,n;

int main() {
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
		s[a[i]]++;
	}
	for(int i=1; i<=s[1]; i++) {
		if(a[i]==1)p[1]++;
		if(a[i]==3)p[4]++;
	}
	for(int i=n; i>=n-s[3]+1; i--) {
		if(a[i]==3)p[3]++;
		if(a[i]==1)p[5]++;
	}
	printf("%d\n",(s[1]-p[1])+(s[3]-p[3])-std::min(p[4],p[5]));
	return 0;
}
