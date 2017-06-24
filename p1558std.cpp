#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<ctime>
#include<cstring>
#define maxn 100001
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
using namespace std;
bool color[maxn<<2][31],query[31];
int col[maxn<<2],sum[maxn<<2],n,t,m;
void build(int l,int r,int rt)
{
    sum[rt]=1;
    color[rt][1]=true;
    if (l==r)return;
    int mid=(l+r)>>1;
    build(lson);
    build(rson);
}
void pushup(int rt)
{
    sum[rt]=0;
    for (int b=1;b<=t;++b)
    {
        color[rt][b]=false;
        if (color[rt<<1][b] || color[rt<<1|1][b])
        {
            color[rt][b]=true;
            sum[rt]++;
        }
    }
}
void pushdown(int rt)
{
    col[rt<<1]=col[rt<<1|1]=col[rt];
    for (int b=1;b<=t;++b)color[rt<<1][b]=false;
    color[rt<<1][col[rt]]=true;sum[rt<<1]=1;
    for (int b=1;b<=t;++b)color[rt<<1|1][b]=false;
    color[rt<<1|1][col[rt]]=true;sum[rt<<1|1]=1;
    col[rt]=0;
}
void update(int l,int r,int rt,int i,int j,int k)
{

    if (i<=l && r<=j)
    {
        col[rt]=k;
        for (int b=1;b<=t;++b)color[rt][b]=false;
        color[rt][k]=true;
        sum[rt]=1;
        return;
    }
    if (col[rt])pushdown(rt);
    int mid=(l+r)>>1;
    if (i<=mid)update(lson,i,j,k);
    if (mid<j)update(rson,i,j,k);
    pushup(rt);
}
void Query(int l,int r,int rt,int i,int j)
{
    if (i<=l && r<=j)
    {
        for (int b=1;b<=t;++b)if (color[rt][b])query[b]=true;
        return;
    }
    if (col[rt])pushdown(rt);
    int mid=(l+r)>>1;
    if (i<=mid)Query(lson,i,j);
    if (mid<j)Query(rson,i,j);
}
int main()
{
    scanf ("%d%d%d",&n,&t,&m);
    build(1,n,1);
    for (int b=1;b<=m;++b)
    {
        char c;
        int i,j,k;
        cin >>c;
        if (c=='C')
        {
            scanf ("%d%d%d",&i,&j,&k);
            if (i>j){int g=i;i=j;j=g;}
            update(1,n,1,i,j,k);
        }
        else
        {
            scanf ("%d%d",&i,&j);
            if (i>j){int g=i;i=j;j=g;}
            Query(1,n,1,i,j);
            int ans=0;
            for (int b=1;b<=t;++b){ans+=query[b];query[b]=0;}
            printf ("%d\n",ans);
        }
    }
    return 0;
}
