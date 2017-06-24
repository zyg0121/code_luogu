#include <cstdio>
#include <cstring>
#include <algorithm>

const int size = 10000+10;
int f[size],w[size],v[size];
int n;

int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		w[i]=i;
		for(int j=1;j<i;j++)
			if(i%j==0) 
				v[i]+=j;
	}
	for(int i=1;i<=n;i++) 
		for(int j=w[i];j<=n;j++) 
			f[j]=std::max(f[j],f[j-w[i]]+v[i]);
	printf("%d\n",f[n]);
	return 0;
}
