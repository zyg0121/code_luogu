#include<iostream>
#include<cstring>
using namespace std;  

int i,j,k,s,t,n,m,f[2501][2501],c[2501],x,y,z,minn,maxx=10e8;
bool b[2501];

int main()  
{    
    ios::sync_with_stdio(false);
	cin>>n>>m>>s>>t;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            f[i][j]=10e7;              
        }
    }
    for(i=1;i<=m;i++)
    {
        cin>>x>>y>>z;
        f[x][y]=z;
        f[y][x]=z;
    }                                  
    for(i=1;i<=n;i++)
    {
        c[i]=f[s][i];
    }
    memset(b,false,sizeof(b));
    b[s]=true;
    c[s]=0;
    for(i=1;i<=n-1;i++)
    {
        minn=maxx;
        k=0;
        for(j=1;j<=n;j++)
        {
            if((!b[j])&&(c[j]<minn))
			{
                minn=c[j];
                k=j;
            }
        }
        if(k==0) break;
        b[k]=true;
        for(j=1;j<=n;j++)
            c[j]=min(c[j],c[k]+f[k][j]);
    }
    cout<<c[t];
    return 0;  
}
