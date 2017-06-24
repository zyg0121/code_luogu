#include <bits/stdc++.h>
using namespace std;

int n,l;
int s;
int maxn,minn;

int main()
{
	ios::sync_with_stdio(false);
	cin>>l>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		maxn+=max(0,max(s,l-s+1)-maxn);
		minn+=max(0,min(s,l-s+1)-minn);
	}
	cout<<minn<<' '<<maxn<<endl;
	return 0;
}
