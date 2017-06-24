#include <cstdio>
#include <cstring>
#include <algorithm>

const int size = 300000+10;
int L,S,T,M;
int a[101],d[101],stone[size];
int f[size];

int read() {
	int f=1,in=0;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())
		if(ch=='-')
			f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())
		in=in*10+ch-'0';
	return in*f;
}

int main() {
    L=read();S=read();T=read();M=read();
    for(int i=1;i<=M;i++)
    	a[i]=read();
    std::sort(a+1,a+M+1);
    for(int i=1;i<=M;i++)
    	d[i]=(a[i]-a[i-1])%2520;// % lcm(1,2,3,4,5,6,7,8,9,10)
    for(int i=1;i<=M;i++) {
    	a[i]=a[i-1]+d[i];
    	stone[a[i]]=1;
    }
    L=a[M];
    for(int i=0;i<=L+T;i++) f[i]=M;
    f[0]=0;
    for(int i=1;i<=L+T;i++) {
    	for(int j=S;j<=T;j++) {
    		if(i>=j) 
    			f[i]=std::min(f[i],f[i-j]);
    		f[i]+=stone[i];
    	}
    }
    int ans=M;
    for(int i=L;i<L+T;i++) ans=std::min(ans,f[i]);
    printf("%d\n",ans);
    return 0;
}
