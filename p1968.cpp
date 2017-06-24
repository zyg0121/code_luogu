#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
double f=0,g=100,x;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lf",&x);
		if(f*100<g*x)
			f=g/100*x;
		else
			g=f*100/x;
	}
	printf("%.2lf\n",g);
	return 0;
}
