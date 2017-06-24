#include <bits/stdc++.h>
using namespace std;

int n,ans;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		ans+=n/i;
	cout<<ans<<endl;
	return 0;
}
