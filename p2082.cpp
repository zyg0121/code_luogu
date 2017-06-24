#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

const int size = 1e6+10;
long long ans,start,endd;
int n;

struct node{
    long long left,right;
}s[size];

bool cmp(const node &a,const node &b)
{
    return a.left<b.left;
}

long long read()
{
    long long in=0,f=1;
    char ch=getchar();
    for(;!isdigit(ch);ch=getchar())
        if(ch=='-')
            f=-1;
    for(;isdigit(ch);ch=getchar())
        in=in*10+ch-'0';
    return in*f;
}

int main()
{
    n=read();
    for(int i=1;i<=n;i++)
    {
        s[i].left=read();
        s[i].right=read();
    }
    
    sort(s+1,s+n+1,cmp);
    start=s[1].left;
    endd=s[1].right;
    for(int i=2;i<=n;i++)
    {
        if(s[i].left<=endd)
            endd=max(endd,s[i].right);
        else
        {
            ans=ans+endd-start+1;
            start=s[i].left;
            endd=s[i].right;
        }
    }
    ans=ans+endd-start+1;
    printf("%lld\n",ans);
    return 0;
}
