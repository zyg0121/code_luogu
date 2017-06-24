#include <bits/stdc++.h>
using namespace std;

int n,m,f[41][41][41][41];
int a[351],b[121];

int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int j=1;j<=m;j++)
	{
		int t;
		cin>>t;
		b[t]++;
	}
	f[0][0][0][0]=a[1];
	for(int i1=0;i1<=b[1];i1++)
		for(int i2=0;i2<=b[2];i2++)
 			for(int i3=0;i3<=b[3];i3++)
				for(int i4=0;i4<=b[4];i4++)
				{
                	int maxn=0;
                	if(i1) maxn=max(maxn,f[i1-1][i2][i3][i4]);
                	if(i2) maxn=max(maxn,f[i1][i2-1][i3][i4]);
                	if(i3) maxn=max(maxn,f[i1][i2][i3-1][i4]);
                	if(i4) maxn=max(maxn,f[i1][i2][i3][i4-1]);
                	f[i1][i2][i3][i4]=maxn+a[1+i1+i2*2+i3*3+i4*4];
            	}
    cout<<f[b[1]][b[2]][b[3]][b[4]]<<endl;
    return 0; 
}
