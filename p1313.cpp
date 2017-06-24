#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
int a,b,k,n,m;
LL f[1001][1001];

int main()
{
	ios::sync_with_stdio(false);
	cin>>a>>b>>k>>n>>m;
	n++;m++;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(i==2&&j==1)
				f[i][j]=a;
			else if(i==1&&j==2)
				f[i][j]=b;
			else
				f[i][j]=(a*f[i-1][j]%10007+b*f[i][j-1]%10007)%10007;
		}
	cout<<f[n][m]<<endl;
	return 0;
}
