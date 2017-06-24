#include <cstdio>
#include <cstring>
#include <algorithm>

int n;

inline void work(int a,int b,int c,int d) {
    int midx=a+c,midy=b+d;
    if(midy>n) return ;
    work(a,b,midx,midy);
    printf("%d/%d\n",midx,midy);
    work(midx,midy,c,d);
}

int main() {
    scanf("%d",&n);
    puts("0/1");
    work(0,1,1,1);
    puts("1/1");
    return 0;
}
