#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef unsigned long long ULL;
ULL a,b,s;

int main() {
    scanf("%llu%llu",&a,&b);
    while (b){
        if (a>b)
            a^=b^=a^=b;
        s+=(b/a)*a*4;
        b%=a;
    }
    printf("%llu\n",s);
    return 0;
}
