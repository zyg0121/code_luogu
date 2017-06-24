#include <bits/stdc++.h>
#define max(a,b) (a>b?a:b)
using namespace std;

int a[50001],f[50001];

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
        for(int j=n;j>=a[i];j--)
            f[j]=max(f[j],f[j-a[i]]+a[i]);
    cout<<f[n]<<endl;
    return 0;
}
