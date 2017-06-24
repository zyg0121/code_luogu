#include <bits/stdc++.h>
using namespace std;

int n,m,k,r;
int f[10010]={0},ti[10001],zyt[10001],zyf[10001];

int main()
{
	scanf("%d%d%d%d",&n,&m,&k,&r);
	for(int i=1;i<=n;i++)
		scanf("%d",&ti[i]);
	for(int i=1;i<=m;i++)
		scanf("%d",&zyt[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&zyf[i]);
	for(int i=1;i<=m;i++)
		for(int j=r;j>=zyt[i];j--)
			f[j]=max(f[j],f[j-zyt[i]]+zyf[i]);
	int b,ans=0;
	for(b=0;b<=r;b++)
	{
		if(f[b]>=k)
		{
			r-=b;
			break;
		}
	}
	sort(ti+1,ti+n+1);
	for(int i=1;i<=n;i++)
	{
		 if (r>=ti[i])
        {
            r-=ti[i];
            ans++;
        }
        else 
        	break;
	}
	cout<<ans<<endl;
	return 0;
}
