#include <bits/stdc++.h>
using namespace std;

int n;
long long f[1001]={1};

bool prime(int x)
{
	int i=2;
    if(x==2)
    	return true;
    while(i<=sqrt(x)&&x%i!=0)
        i++;
    if(x%i==0)
    	return false;
    else
    	return true;
}

int main()
{
    scanf("%d",&n);
    for(int i=2;i<=n;++i) 
		if(prime(i)) 
			for(int j=i;j<=n;++j) 
				f[j]+=f[j-i];
    cout<<f[n]<<endl;
    return 0;
}
