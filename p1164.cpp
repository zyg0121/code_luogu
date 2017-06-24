#include<cstdio>

int n,m,a[101],f[10001],count,max; 

int main()
{
    f[0]=1;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        for(int j=m;j>=a[i];j--)
            f[j]+=f[j-a[i]];
    printf("%d",f[m]);
    return 0;
}
