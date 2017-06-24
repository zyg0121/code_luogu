#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int a[101][101],b[101][101];
int n,m,ans=0;
int xx,yy;
const int fx[]={0,1,0,-1};
const int fy[]={1,0,-1,0};

int ss(int x,int y)
{
	if(b[x][y]!=-1)
		return b[x][y];
	int p=0;
	for(int i=0;i<4;i++)
	{
		xx=x+fx[i];
		yy=y+fy[i];
		if((xx<n and xx>=0 and yy<=m and yy>=0)and(a[xx][yy]>a[x][y]))
			p=max(ss(xx,yy),p);
	}
	b[x][y]=p+1;
	return b[x][y];
}

int main()
{
	memset(b,-1,sizeof(b));
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",&a[i][j]);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			ans=max(ans,ss(i,j));
	cout<<ans-1<<endl;
	return 0;
}
