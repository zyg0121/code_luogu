#include<cstdio>
#include<cmath>
#include<ctime>
#include<cstring>
#include<iostream>
#include<algorithm>
const int inf = 1000000000;
const int N = 10000000;
typedef long long ll ;
using namespace std;

int read() {
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9') {
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x;
}

int T,R,n,m,cnt;
int fac[10000005],ine[10000005],pri[500005],ans[10000005];
bool mark[10000005];

void exgcd(int a,int b,int &x,int &y) {
	if(b==0) {
		x=1;
		y=0;
		return;
	}
	exgcd(b,a%b,x,y);
	int t=x;
	x=y;
	y=t-a/b*y;
}
int getine(int t) {
	int x,y;
	exgcd(t,R,x,y);
	return (x%R+R)%R;
}

void pre() {
	fac[1]=1;
	for(int i=2; i<=N; i++)fac[i]=(ll)fac[i-1]*i%R;
	ine[1]=1;
	for(int i=2; i<=N; i++) {
		if(!mark[i])pri[++cnt]=i,ine[i]=getine(i);
		for(int j=1; pri[j]*i<=N&&j<=cnt; j++) {
			mark[pri[j]*i]=1;
			if(i%pri[j]==0)break;
		}
	}
	ans[1]=1;
	for(int i=2; i<=N; i++) {
		ans[i]=ans[i-1];
		if(!mark[i])ans[i]=(ll)ans[i]*(i-1)%R*ine[i]%R;
	}
}
int main() {
	T=read();
	R=read();
	pre();
	while(T--) {
		n=read();
		m=read();
		printf("%d\n",(ll)fac[n]*ans[m]%R);
	}
	return 0;
}
