#include<bits/stdc++.h>
using namespace std;

const int size = 100001;
int A,B,p,prime[size],f[size],ans=0;
bool not_prime[size],s[size];

void make_prime()
{
    for(int i=2;i<=B;i++)
        if(!not_prime[i])
        {
            if(i>=p)prime[++prime[0]]=i;
            for(int j=2;i*j<=B;j++)
                not_prime[i*j]=true;
        }
        
}

int find(int x)
{
	return f[x]==x ? x : f[x]=find(f[x]);
}

int unionn(int x,int y)
{
    f[find(x)]=find(y);
}

int main()
{
    scanf("%d%d%d",&A,&B,&p);
    make_prime();
    for(int i=1;i<=B;i++)
        f[i]=i;
    
    for(int i=1;i<=prime[0];i++)
        for(int j=ceil(A*1.0/prime[i]);prime[i]*j<=B;j++)
            unionn(prime[i],prime[i]*j);
    for(int i=A;i<=B;i++)
        s[find(i)]=1;
    for(int i=A;i<=B;i++)
        if(s[i])ans++;
        
    printf("%d\n",ans);
    return 0;
}
