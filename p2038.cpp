#include <bits/stdc++.h>
using namespace std;

int n,x[30],y[30],s[30],maxn,ans,f[130][130],d;

int main()
{
	ios::sync_with_stdio(false);
	cin>>d>>n;
	for(int i=0;i<n;i++)
		cin>>x[i]>>y[i]>>s[i];
	for(int i=0;i<129;i++)
    	for(int j=0;j<129;j++)
    		for(int k=0;k<n;k++)
    			if(x[k]>=i-d&&x[k]<=i+d&&y[k]>=j-d&&y[k]<=j+d)
					f[i][j]+=s[k];
	for(int i=0;i<129;i++)
		for(int j=0;j<129;j++)
			maxn=max(f[i][j],maxn);
	for(int i=0;i<129;i++)
		for(int j=0;j<129;j++)
			if(maxn==f[i][j])
				ans++;
	cout<<ans<<' '<<maxn<<endl;
	return 0;
}
