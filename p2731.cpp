#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;

int map[505][505];
int path[1050];
int pathnum;
int minv=1<<30,maxv=0;

void circle(int v)
{
    for (int i=minv;i<=maxv;i++)
        while(map[i][v]>0)
        {
            map[i][v]--;
            map[v][i]--;
            circle(i);
        }
    path[pathnum++]=v;
}
int main()
{
    int f;
    cin>>f;
    memset(map,0,sizeof(map));
    for (int i=0;i<f;i++)
    {
        int a,b;
        cin>>a>>b;
        minv=min(a,minv);
        	minv=min(b,minv);
        maxv=max(a,maxv);
        	maxv=max(b,maxv);
        map[a][0]++;
        map[b][0]++;
        map[a][b]++;
        map[b][a]++;
    }
    int k=minv;
    for (int i=minv;i<=maxv;i++)
        if (map[i][0]%2==1)
        {
            k=i;
            break;
        }
    circle(k);
    for (int i=pathnum-1;i>=0;i--)
        cout<<path[i]<<endl;
    return 0;
}
