#include <bits/stdc++.h>
using namespace std;

string s;
int x[3];
char ch;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        memset(x,0,sizeof(x));
        for(int j=1;j<=2;j++)
        {
            cin>>s;
            if(s=="a")
            {
                ch='+';
                j--;
            }
            else if(s=="b")
            {
                ch='-';
                j--;
            }
            else if(s=="c")
            {
                ch='*';
                j--;
            }
            else
            {
                int l=s.size();
                for(int k=0;k<l;k++)
                    x[j]=x[j]*10+s[k]-'0';
            }
        }
        int ans=0;
        if(ch=='+') 
			ans=x[1]+x[2];
        else if(ch=='-') 
			ans=x[1]-x[2];
        else 
			ans=x[1]*x[2];
        printf("%d%c%d=%d\n",x[1],ch,x[2],ans);
        int total=2;
        if(ans<0) 
			total++;
        if(!x[1]) 
			total++;
        while(x[1]) 
			x[1]/=10,total++;
        if(!x[2]) 
			total++;
        while(x[2]) 
			x[2]/=10,total++;
        if(!ans) 
			total++;
        while(ans) 
			ans/=10,total++;
        cout<<total<<endl;
    }
    return 0;
}
