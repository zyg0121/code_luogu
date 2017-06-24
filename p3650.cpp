#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

const int size = 1000+10;
const int INF = 2147483467;

int a[size];
int n,sum,maxd,ans=INF,minn=INF;

int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),maxd=std::max(maxd,a[i]);
	for(int j=0;j<=maxd;j++) {
		sum=0;
		for(int i=1;i<=n;i++) {
			if(a[i]<j and j-a[i]>17) sum+=pow((j-a[i]-17),2);
			if(a[i]>j) sum+=pow((a[i]-j),2);
		}
		ans=std::min(ans,sum);
	}
	printf("%d\n",ans);
	return 0;
}
