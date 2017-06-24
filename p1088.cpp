#include <bits/stdc++.h>
using namespace std;

const int size = 10001;
int a[size];
int n,m;

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int cnt = 0;
	while(cnt<m)
	{
		next_permutation(a+1,a+n+1);
		cnt++;
	}
	for(int i=1;i<=n;i++)
		cout<<a[i]<<' ';
	return 0;
}
