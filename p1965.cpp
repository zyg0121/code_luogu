#include <bits/stdc++.h>
using namespace std;

long long n,m,k,x;
long long ans,a=10;

int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m>>k>>x;
	ans=1;
	while(k>0)
	{
		if(k%2==1)
			ans=ans*a%n;
		k=k/2;
		a=a*a%n;
	}
	ans=(x+m*ans)%n;
	cout<<ans<<endl;
	return 0;
}
