#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int size = 100001;
int n,m,ans;
struct edge
{
    int to,l;
}d1[1001][1001];
int x[size],y[size],z[size];
int len[1001];

void spfa()
{
    bool inque[1001];
    int u,v;
    queue<int>q;
    q.push(1);inque[1]=1;
    int d[1001];
    memset(d,127,sizeof(d));
    memset(inque,0,sizeof(inque));
    d[1]=0;
    while(!q.empty())
    {
        u=q.front();q.pop();inque[u]=0;
        for(int i=1;i<=len[u];i++)
        {
            v=d1[u][i].to;
            if(d1[u][i].l+d[u]<d[v])
            {
                d[v]=d1[u][i].l+d[u];
                if(!inque[v])
                {
                    q.push(v);
                    inque[v]=1;
                }
            }
        }
    }
    for(int i=2;i<=n;i++)
    	ans+=d[i];
}

int main()
{
    scanf("%d%d",&n,&m);
    edge tmp;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&x[i],&y[i],&z[i]);
        d1[x[i]][++len[x[i]]].to=y[i];
        d1[x[i]][len[x[i]]].l=z[i];
    }
    spfa();
    memset(d1,0,sizeof(d1));
    memset(len,0,sizeof(len));
    for(int i=1;i<=m;i++)
    {
        d1[y[i]][++len[y[i]]].to=x[i];
        d1[y[i]][len[y[i]]].l=z[i];
    }
    spfa();
    printf("%d",ans);
}
