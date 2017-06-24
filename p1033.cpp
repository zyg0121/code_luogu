#include <bits/stdc++.h>
using namespace std;

double h,s,v,l,k,n;
double g=10.0,eps=0.0001;
int ans;

int main()
{
	ios::sync_with_stdio(false);
	cin>>h>>s>>v>>l>>k>>n;
	for(int i=0;(i<n)&&(i<=s);i++)
	{
		if((v>-eps+(s-i)*sqrt(g/(2*h)))&&(v<eps+(s-i+l)*sqrt(g/(2*(h-k)))))
			ans++;
	}
	cout<<ans<<endl;
}
