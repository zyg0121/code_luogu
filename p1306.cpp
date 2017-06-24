#include <cstdio>
#include <iostream>
typedef long long LL:
using namespace std;

const int MOD = 1e8;

LL gcd(LL a,LL b){
    return !b?a:gcd(b,a%b);
}

LL fast_mod(LL n)    
{
    LL t[2][2] = {1, 1, 1, 0};
    LL ans[2][2] = {1, 0, 0, 1};  
    LL tmp[2][2]; 
    while(n)
    {
        if(n & 1)
        {
            for(int i = 0; i < 2; ++i)
                for(int j = 0; j < 2; ++j)
                    tmp[i][j] = ans[i][j]; 
            ans[0][0] = ans[1][1] = ans[0][1] = ans[1][0] = 0;
            
            for(int i = 0; i < 2; ++i)
            {
                for(int j = 0; j < 2; ++j)
                {
                    for(int k = 0; k < 2; ++k)
                        ans[i][j] = (ans[i][j] + tmp[i][k] * t[k][j]) % MOD;
                }
            }
        }
        for(int i = 0; i < 2; ++i)
            for(int j = 0; j < 2; ++j)
                tmp[i][j] = t[i][j];
        t[0][0] = t[1][1] = 0;
        t[0][1] = t[1][0] = 0;
        for(int i = 0; i < 2; ++i)
        {
            for(int j = 0; j < 2; ++j)
            {
                for(int k = 0; k < 2; ++k)
                    t[i][j] = (t[i][j] + tmp[i][k] * tmp[k][j]) % MOD;
            }
        }
        n >>= 1;
    }
    return ans[0][1];
}

int main()
{
    LL n,m;
    scanf("%lld%lld",&n,&m);
    n=gcd(n,m);
    printf("%lld\n", fast_mod(n));
    return 0;
}
