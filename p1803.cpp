#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

struct node {
	int x,y;
}p[1000001];

bool cmp(const node a,const node b)
{
	if((a.y<b.y)||(a.y==b.y)&&(a.x<b.x))
		return true;
	else
		return false;
}

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i].x>>p[i].y;
	sort(p+1,p+n+1,cmp);
	int k=0,l=0;
	for(int i=1;i<=n;i++)
		if(k<=p[i].x)
		{
			k=p[i].y;
			l++;
		}
	cout<<l<<endl;
	return 0;
}
