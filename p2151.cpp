#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
const int p = 45989;
const int N = 200;
using namespace std;

int n,m,t,a,b,tot;
int point[N],nxt[N],v[N],w[N];
struct matrix {
    int a[123][123];
}dis,start;

void add(int x,int y)
{
    nxt[++tot]=point[x]; w[tot]=x; v[tot]=y; point[x]=tot;
    nxt[++tot]=point[y]; w[tot]=y; v[tot]=x; point[y]=tot;
}
void clear(matrix &x)
{
    for (int i=0;i<=tot;i++)
        for (int j=0;j<=tot;j++)
            x.a[i][j]=0;
}
void change(matrix &a,matrix b)
{
    for (int i=0;i<=tot;i++)
        for (int j=0;j<=tot;j++)
            a.a[i][j]=b.a[i][j];
}
matrix mul(matrix a,matrix b)
{
    matrix c;
    for (int i=0;i<=tot;i++)
        for (int j=0;j<=tot;j++) {
            c.a[i][j]=0;
        for (int k=0;k<=tot;k++)
            c.a[i][j]=(c.a[i][j]+a.a[i][k]*b.a[k][j]%p)%p;
    }
    return c;
}
matrix pow(matrix num,int x)
{
    matrix ans; clear(ans);
    for (int i=0;i<=tot;i++)  ans.a[i][i]=1;
    matrix base; change(base,num);
    while (x)
    {
        if (x&1) 
            ans=mul(ans,base);
        x>>=1;
        base=mul(base,base);
    }
    return ans;
}
void build()
{
    for (int i=0;i<=tot;i++)
        for (int j=0;j<=tot;j++)
            if (v[i]==w[j]&&i!=(j^1))
                dis.a[i][j]=1;
}
int main()
{
    scanf("%d%d%d%d%d",&n,&m,&t,&a,&b);
    tot=-1;
    memset(point,-1,sizeof(point));
    memset(nxt,-1,sizeof(nxt));
    a++; b++;
    clear(dis);
    for (int i=1,x,y;i<=m;i++) {
        scanf("%d%d",&x,&y);
        x++; y++;
        add(x,y);
    }
    build(); 
    for (int i=point[a];i!=-1;i=nxt[i])
        start.a[0][i]++;
    matrix t1=pow(dis,t-1);
    matrix ans;
    for (int i=0;i<=tot;i++) {
        ans.a[0][i]=0;
        for (int k=0;k<=tot;k++)
         ans.a[0][i]=(ans.a[0][i]+start.a[0][k]*t1.a[k][i]%p)%p;
    }
    int sum=0;
    for (int i=point[b];i!=-1;i=nxt[i])
        sum=(sum+ans.a[0][i^1])%p;
    printf("%d\n",sum%p);
    return 0;
}
