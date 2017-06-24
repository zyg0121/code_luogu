#include <bits/stdc++.h>
using namespace std;

const int size = 1001;
int num[size][size];
int n,m;

int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		int x1,x2,y1,y2;
		cin>>x1>>y1>>x2>>y2;
		for(int j=x1;j<=x2;j++)
			for(int k=y1;k<=y2;k++)
				num[j][k]++;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			cout<<num[i][j]<<' ';
		cout<<endl;
	}	
	return 0;
}
