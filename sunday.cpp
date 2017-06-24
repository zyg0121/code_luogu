#include <bits/stdc++.h>
using namespace std;

int wei[1001];
int ans=0,lend,lenc;
string c,d;

void pei()
{
    int w=0;
    while(w+lend<=lenc)
    {
        int i=0;
        bool f=false;
        while(i<=lend && f==false)
        {
            if(c[i+w]!=d[i]) f=true;
            i++;
        }
        if(f==false) {
        	cout<<w+1<<endl;
			ans++;w++;
		}
        else
        {
            i=lend+1;
            if(wei[c[i+w]]==-1)w=w+i+1;
            else w=w+i-wei[c[w+i]];
        }
    }
    return;
}
int main()
{
    cin>>c;
    cin>>d;
    lenc=c.length()-1;
    lend=d.length()-1;
    for(int i=0;i<=1000;++i)wei[i]=-1;
    for(int i=0;i<=lend;++i)
    wei[d[i]]=i;
    pei();
    for(int i=0;i<=lend;i++)
    	printf("%d ",wei[i]);
    return 0;
}
