#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

int t,k;
int a[1001];
int f[1000][3][31];

int dp(int,int,int);

int main()
{
	scanf("%d%d",&t,&k);
	for(int i=1;i<=t;i++)
		scanf("%d",&a[i]);
	cout<<dp(1,1,k)<<endl;
	return 0;
}

int dp(int i,int now,int left)
{
	if(i>t)
		return 0;
    if(left<0)
		return 0;
    if(f[i][now][left])
		return f[i][now][left];
    return f[i][now][left]=(a[i]==now)+max(dp(i+1,now,left),dp(i+1,3-now,left-1));
}
