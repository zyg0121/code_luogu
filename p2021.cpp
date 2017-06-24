#include <bits/stdc++.h>
using namespace std;

int a[1000001];
int n;

int main()
{
    scanf("%d",&n);
    int s=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=2;j++)
        {
            s++;
            if(s==n+1) 
				s=1;
            if(a[s])
				j--;
        }
        a[s]=i;
    }
    for(int i=1;i<=n;i++)
		cout<<a[i]<<' ';
    return 0;
}
