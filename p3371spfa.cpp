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

void SPFA(int s)
{
    for(int i=1;i<=n;i++) 
		dis[i]=INF; 
	dis[s]=0;
    queue<int>Q;
	Q.push(s);
    while(!Q.empty()) 
	{
        int u=Q.front(); 
		Q.pop();
        for(int e=fir[u];e;e=nxt[e]) 
		{
            int v=to[e],w=val[e];
            if(dis[u]+w<dis[v]) 
			{
                dis[v]=dis[u]+w;
                if(!vis[v]) 
					Q.push(v);
            }
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
	SPFA(s);
	for(int i=1;i<=n;i++)
		printf("%d ",dis[i]);
	return 0;
}
