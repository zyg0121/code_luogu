#include <bits/stdc++.h>
using namespace std;

int f[3001];
int n,m,maxans=0,last;
char ch;

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
        {
            int x;scanf("%d",&x);
            int t=f[j];
            if(x==0) 
				f[j]=0;
            else
			{
                f[j]=min(f[j],min(f[j-1],last))+1;
                maxans=max(maxans,f[j]);
            }
            last=t;
        }
    printf("%d\n",maxans);
    return 0;
}
