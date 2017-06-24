#include <cstdio>
#include <cstring>
#include <algorithm>

const int size = 10000+10;

int f[size],w[110][size],c[110][size],a[size];
int m,n,t;

int main() {
	scanf("%d%d",&m,&n);
	for(int i=1,x,y,z;i<=n;i++) {
		scanf("%d%d%d",&x,&y,&z);
		t=std::max(z,t);a[z]++;
		w[z][a[z]]=x;c[z][a[z]]=y;
	}
	for(int k=1;k<=t;k++) 
		for(int j=m;j>=0;j--) 
			for(int i=1;i<=a[k];i++)
				if(j>=w[k][i])
					f[j]=std::max(f[j],f[j-w[k][i]]+c[k][i]);
	printf("%d\n",f[m]);
	return 0;
}
