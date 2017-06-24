#include <cstdio>
#include <cstring>
#include <algorithm>

int t;

int main() {
    scanf("%d",&t);
    while(t--) {
	int m,u,x;
	scanf("%d",&m);
        int sum=0;
        for(j=0;j<m;j++)
        {
            scanf("%d",&u);
            if(sum==0)
		x=u;
            if(x==u)
		sum++;
	    else
		sum--;
        }
        printf("%d\n",x);
    }
    return 0;
}
