#include <bits/stdc++.h>
using namespace std;

int k,n;
double ans,x[20],y[20];
bool vis[20];

int dfs(int,double,double,double);

int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>x[i]>>y[i];
	ans=1000000;
	dfs(1,0,0,0);
	printf("%.2lf",ans);
	return 0;
}

int dfs(int t,double sx,double sy,double sum)
{
	if(t>n)
	{
		ans=min(ans,sum);
		return 0;
	}
	if(sum>=ans)
		return 0;
	for(int i=1;i<=n;i++)
		if(vis[i]==false)
		{
			vis[i]=true;
			dfs(t+1,x[i],y[i],sum+sqrt((x[i]-sx)*(x[i]-sx)+(y[i]-sy)*(y[i]-sy)));
			vis[i]=false;
		}
	return 0;
}
