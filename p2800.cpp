#include<bits/stdc++.h>
using namespace std;

int n,a,f[1000010]; 

int main()
{ 
	scanf("%d",&n); 
	for(int i=3;i<=n+2;i++)
	{ 
		scanf("%d",&a); 
		f[i]=min(f[i-1],min(f[i-2],f[i-3]))+a;	 
	} 
	printf("%d\n",min(f[n+1],min(f[n],f[n-1]+a)));
	return 0; 
}
