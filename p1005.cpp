#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn=80+10;

struct BIGNUM 
{
    int num[maxn],len;
    BIGNUM(){memset(num,0,sizeof(num));len=1;}
    BIGNUM operator = (const char str[]) 
	{
        len=strlen(str);
        for(int i=0;i<len;i++)
            num[i]=str[len-i-1]-'0';
        while(num[len-1]==0&&len>1) len--;
        return *this;
    }
    BIGNUM operator = (const int n) 
	{
        int tmp=n;
        len=1;
        do 
		{
            num[len-1]=tmp%10;
            tmp/=10;len++;
        }while(tmp>0);
        while(num[len-1]==0&&len>1) len--;
        return *this;
    }
    BIGNUM operator + (const BIGNUM &rhs) const
	 {
        BIGNUM tmp;
        tmp.len=max(len,rhs.len)+1;
        for(int i=0;i<tmp.len;i++)
		 {
            tmp.num[i]+=num[i]+rhs.num[i];
            tmp.num[i+1]=tmp.num[i]/10;
            tmp.num[i]%=10;
        }
        while(tmp.num[tmp.len-1]==0&&tmp.len>1) tmp.len--;
        return tmp;
    }
    BIGNUM operator * (const BIGNUM &rhs) const 
	{
        BIGNUM tmp;
        tmp.len=len+rhs.len;
        for(int i=0;i<len;i++)
            for(int j=0;j<rhs.len;j++) 
			{
                tmp.num[i+j]+=num[i]*rhs.num[j];
                tmp.num[i+j+1]+=tmp.num[i+j]/10;
                tmp.num[i+j]%=10;
            }
        while(tmp.num[tmp.len-1]==0&&tmp.len>1) tmp.len--;
        return tmp;
    }
    bool operator < (const BIGNUM &rhs) const 
	{
        if(len>rhs.len) return false;
        if(len<rhs.len) return true;
        for(int i=len-1;i>=0;i--)
            if(num[i]!=rhs.num[i]) return num[i]<rhs.num[i];
        return false;
    }
    void print() 
	{
        for(int i=len-1;i>=0;i--) printf("%d",num[i]);
    }
}dp[maxn][maxn];
BIGNUM ans;

int a[maxn];

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    BIGNUM pow;
    pow=2;
    for(int i=1;i<=n;i++) 
	{
        memset(dp,0,sizeof(dp));
        for(int j=1;j<=m;j++) 
		{
            scanf("%d",&a[j]);
            dp[j][j]=a[j]*2;
        }
        for(int x=2;x<=m;x++)
            for(int l=1;l<=m;l++) 
			{
                int r=l+x-1;
                if(r>m) continue;
                dp[l][r]=max(dp[l+1][r]*pow+dp[l][l],dp[l][r-1]*pow+dp[r][r]);//dp
            }
        ans=ans+dp[1][m];
    }
    ans.print();
    return 0;
}
