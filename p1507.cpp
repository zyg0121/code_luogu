#include <bits/stdc++.h>
using namespace std;

int f[410][410],v,m,n,x,y,z;

int main()
{
    ios::sync_with_stdio(false);
    cin>>v>>m>>n;
    for(int q=n;q>0;q--)
	{
        cin>>x>>y>>z;
        for (int i=v;i>=x;i--)
            for (int j=m;j>=y;j--)
                f[i][j]=max(f[i][j],f[i-x][j-y]+z);
    }
    cout<<f[v][m]<<endl;
    return 0;
}
