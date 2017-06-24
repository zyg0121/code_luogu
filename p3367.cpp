#include <bits/stdc++.h>
using namespace std;

const int maxn=10010;
int fa[maxn];
int k,m,n;

int find(int x)
{
	return fa[x]=x==fa[x]?x:find(fa[x]) ;
}

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	while(m--)
	{
		int op,a,b;
		cin>>op>>a>>b;
		if(op==1)
			fa[find(a)]=find(b);
		else
			printf("%c\n",find(a)==find(b)?'Y':'N');
	}
	return 0;
}
