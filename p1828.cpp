#include <bits/stdc++.h>
using namespace std;
struct e        
{
    int next,to,cost;
}e[100001];
int cow[100001],head[100001],team[100001],vis[100001],minn[10001];
int n,p,c,u,sum,ans=0x7fffff,num;

void add(int from,int to,int dis)          
{
    e[++num].next=head[from];
    e[num].to=to;
    e[num].cost=dis;
    head[from]=num;
}

void spfa(int s)
{
    memset(team,0,sizeof(team));
    memset(vis,0,sizeof(vis));
    memset(minn,0x7f,sizeof(minn));
    int h=0,t=1;
    minn[s]=0;
    vis[s]=1;
    team[1]=s;
    while(h<t)
    {
        h++;          
        u=team[h];       
        vis[u]=0;
        for(int j=head[u];j!=0;j=e[j].next)
        {
            int to=e[j].to;
            if(minn[u]+e[j].cost<minn[to])
            {
                minn[to]=minn[u]+e[j].cost;
                if(vis[to]==0)
                {
                    t++;
                    vis[to]=1;
                    team[t]=to;
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
	cin>>n>>p>>c;
    for(int i=1;i<=n;i++)
    {
        int num;
        cin>>cow[i];      
    }
    for(int i=1;i<=c;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        add(x,y,z);     
        add(y,x,z);
    }
    for(int i=1;i<=p;i++)       
    {
        spfa(i);
        sum=0;
        for(int j=1;j<=n;j++)
            sum=sum+minn[cow[j]];      
        if(sum<ans) ans=sum;
    }
    cout<<ans<<endl;
    return 0;
}
