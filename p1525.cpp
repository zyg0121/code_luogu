#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int size = 100001;
int n,m,father[size/5*2+1];

struct node{
	int a,b,c;
}e[size];

bool cmp(node a,node b)
{	
	return a.c>b.c;
}

int find(int x)
{
	return father[x]==x ? x : father[x]=find(father[x]);
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].c);
	for(int i=1;i<=n*2;i++)
		father[i]=i;
	sort(e+1,e+m+1,cmp);
	for(int i=1,fx,fy;i<=m;i++)
	{
		fx=find(e[i].a);
		fy=find(e[i].b);
		if(fx==fy)
			return printf("%d\n",e[i].c),0;
		father[fy]=find(e[i].a+n);
		father[fx]=find(e[i].b+n);
	}
	printf("0\n");
	return 0;
}
