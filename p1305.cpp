#include <bits/stdc++.h>
using namespace std;

int n;
string a[30];

void dg(string b)
{
	cout<<b[0];
	for(int i=1;i<=b.size();i++)
	{
		if(b[i]=='*')
			continue;
		for(int j=0;j<n;j++)
			if(a[j][0]==b[i])
				dg(a[j]);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	dg(a[0]);
	return 0;
}
