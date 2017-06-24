#include <cstdio>
#include <iostream>
using namespace std;
int n,a1,a2,sum;
int main()
{
    scanf("%d%d",&n,&a1);
    sum=a1;
    for(int i=2;i<=n;i++)
    {
        scanf("%d",&a2);
        if(a1>0)
			a2+=a1;
        if(sum<a2)
			sum=a2;
        a1=a2;
    }
    printf("%d\n",sum);
    return 0;
}
