#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int a[19],f[100001],m;

int main()
{
    scanf("%d",&m);
    int s=1;
    while(s*s*s*s<=m)
    {
        a[s]=s*s*s*s;
        s++;
    }
    memset(f,0x7f,sizeof(f));
    f[0]=0;
    for(int i=1;i<s;i++)
    	for(int j=a[i];j<=m;j++)
    	f[j]=min(f[j],f[j-a[i]]+1);
    printf("%d",f[m]);
    return 0;
}
