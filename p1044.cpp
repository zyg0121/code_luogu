#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

int n;
double dp[20];
int main() 
{
    scanf("%d",&n);
    dp[0]=dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        double temp=(4*i-2.0)/(i+1.0);
        dp[i]=temp*dp[i-1];
    }
    printf("%.lf\n",dp[n]);
    return 0;
}
