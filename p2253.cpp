#include <iostream>
#include <cstdio>
using namespace std;
const int size = 50000+10;

int p[size];

int main()
{
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for (int i=0;i<m;i++)
    {
        int k;
        cin>>k;
        if (p[k-1]==0) p[k-1]=1;
        else p[k-1]=0;
        int max=1,sum=1;
        for (int b=1;b<n;b++)
        {
            if (sum>max) max=sum;
            if (p[b]!=p[b-1])
                sum++;
            else sum=1;
        }
        if(sum>max) max=sum;
        cout<<max<<endl;
    }
    return 0;
}
