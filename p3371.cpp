#include <bits/stdc++.h>
using namespace std;

const int INF = 2147483647;
const int maxn = 10010;
const int maxm = 500010;

int n,m,s;
int fir[maxn],nxt[maxm],to[maxm],val[maxm],cnt;
int dis[maxn],vis[maxn];
int u,v,w;

void add_edge(int u,int v,int w)
{
	nxt[++cnt]=fir[u];
	fir[u]=cnt;
	to[cnt]=v;
	val[cnt]=w;
}

void Dijkstra(int s)
{
	for(int i=1;i<=n;i++)
		dis[i]=INF;
	dis[s]=0;
	for(int i=1;i<=n;i++)
	{
		int pos,mn=INF;
		for(int j=1;j<=n;j++)
			if(!vis[j]&&dis[j]<mn)
				mn=dis[pos=j];
		vis[pos]=1;
		for(int e=fir[pos];e;e=nxt[e])
		{
			int v=to[e],w=val[e];
			if(!vis[v]&&mn+w<dis[v])
				dis[v]=mn+w;
		}
	}
}

int main()
{
	scanf("%d%d%d",&n,&m,&s);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		add_edge(u,v,w);
	}
	Dijkstra(s);
	for(int i=1;i<=n;i++)
		printf("%d ",dis[i]);
	return 0;
}
