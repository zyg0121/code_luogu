#include <bits/stdc++.h>
using namespace std;

int m,n,a,b;

int exgcd(int a,int b,int &x,int &y)
{
	if(b==0)
	{
		y=0;x=1;
		return a;
	}
	int q=exgcd(b,a%b,x,y);
	int temp=x;x=y;y=temp-a/b*y;
	return q;
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>m>>n;
	int gcd=exgcd(m,n,a,b);
	cout<<((a%n+n)%n)<<endl;
	return 0;
}
