#include<cstdio>
#include<cstring>
#include<algorithm>
const int N = 300005;
#define reg register
using namespace std;

struct edge {
	int next,to,val;
}e[N<<1];
int ecnt;
int n, m, last[N], fa[N], dep[N], siz[N], top[N], son[N];
int u[N], v[N], d[N], dis[N], Lca[N], f[N], mxlen, mx, tot, b[N];
int read()
{
    reg int r=0;
    reg char c=getchar();
    while(c<'0'||c>'9')c=getchar();
    while(c>='0'&&c<='9')r=r*10+c-'0',c=getchar();
    return r;
}

void addedge(int a, int b, int c)
{
    e[++ecnt]=(edge){last[a],b,c};
    last[a]=ecnt;
}

void dfs1(int x)
{
    dep[x]=dep[fa[x]]+1;
    siz[x]=1;
    for(int i = last[x]; i; i=e[i].next)
    {
        int y=e[i].to;
        if(y==fa[x])continue;
        fa[y]=x;
        dis[y]=dis[x]+e[i].val;
        dfs1(y);
        siz[x]+=siz[y];
        if(siz[y]>siz[son[x]])
            son[x]=y;
    }
}

void dfs2(int x)
{
    if(son[fa[x]]==x)top[x]=top[fa[x]];
    else top[x]=x;
    for(int i = last[x]; i; i=e[i].next)
    {
        int y=e[i].to;
        if(y!=fa[x])
            dfs2(y);
    }
}

int lca(int a, int b)
{
    while(top[a]!=top[b])
    {
        if(dep[top[a]]>dep[top[b]])
            a=fa[top[a]];
        else b=fa[top[b]];
    }
    return dep[a]>dep[b]?b:a;
}

void make(int i)
{
    f[u[i]]++;
    f[v[i]]++;
    f[Lca[i]]-=2;
}

void find(int x)
{
    b[x]=f[x];
    for(int i = last[x]; i; i=e[i].next)
    {
        int y=e[i].to;
        if(y==fa[x])continue;
        find(y);
        b[x]+=b[y];
        if(b[y]==tot)
            mx=max(mx,e[i].val);
    }
}

bool check(int lim)
{
    tot=0;
    memset(f,0,sizeof(f));
    for(int i = 1; i <= m; i++)
        if(d[i]>lim)
        {
            ++tot;
            make(i);
        }
    mx=0;
    find(1);
    return mxlen-mx<=lim;
}

int main()
{
    n=read(), m=read();
    for(int i = 1; i < n; i++)
    {
        int a=read(), b=read(), t=read();
        addedge(a,b,t);
        addedge(b,a,t);
    } 
    dfs1(1);
    dfs2(1);
    for(int i = 1; i <= m; i++)
    {
        u[i]=read(), v[i]=read(); 
        d[i]=dis[u[i]]+dis[v[i]]-2*dis[Lca[i]=lca(u[i],v[i])];
        mxlen=max(mxlen,d[i]);
    }   
    int l = max(0,mxlen-1000), r = mxlen;
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(check(mid))r=mid;
        else l=mid+1;
    }
    printf("%d\n",l);
    return 0;
}
