#include<cstdio>

#define min(a,b) (a)<(b) ? (a) : (b)
typedef long long LL;
const int N=100005,K=105;
int n,k,x[K];
LL s[K],q[N];

int main()
{
    scanf("%d%d",&k,&n);
    for(int i=1;i<=k;i++)
        scanf("%lld",&s[i]);
    int rear=0;
    q[0]=1;
    while(rear<n)
    {
        LL tmp=1LL<<60;
        for(int i=1;i<=k;i++)
            tmp=min(tmp,q[x[i]]*s[i]);
        q[++rear]=tmp;
        for(int i=1;i<=k;i++)
            if(tmp==q[x[i]]*s[i])
                ++x[i];
    }
    printf("%lld\n",q[n]);
    return 0;
}
