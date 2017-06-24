#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long LL;
int n,m,p;
int x[101][3][3],y[3][3],z[3][3],a[101],k1,k2,ans;
int i,j,k,l;

int main() {
	scanf("%d%d%d",&n,&m,&p);
	m--;
	x[0][1][2]=x[0][2][1]=x[0][2][2]=1;
	a[0]=1;
	for(i=1;a[i-1]*2<=m;i++) {
		a[i]=a[i-1]*2;
		for(j=1;j<=2;j++)
			for(k=1;k<=2;k++) 
				for(l=1;l<=2;l++)
					x[i][j][k]=(x[i][j][k]+(LL)x[i-1][j][l]*x[i-1][l][k])%p;
	}
	y[1][1]=y[2][2]=1;
	for(i--;i>=0;i--) {
		if(a[i]<=m) {
			m-=a[i];
			for(j=1;j<=2;j++) 
				for(k=1;k<=2;k++)
					for(l=1;l<=2;l++) 
						z[j][k]=(z[j][k]+(LL)x[i][j][l]*y[l][k])%p;
			for(j=1;j<=2;j++) 
				for(k=1;k<=2;k++) {
					y[j][k]=z[j][k];
					z[j][k]=0;
				}
		}
	}
	k1=((LL)(n*(1+sqrt(5))/2+n-1))%p;
	k2=((2*k1-n+1)%p+p)%p;
	ans=((LL)k1*y[1][1]+(LL)k2*y[1][2])%p;
	printf("%d\n",ans);
	return 0;
}
