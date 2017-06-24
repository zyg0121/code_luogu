#include <cstdio>
#include <iostream>
using namespace std;

int n;
long long ans;

long long euler(int n) {  
    long long res=n,a=n;  
    for(int i=2;i*i<=a;i++) {  
        if(a%i==0) {  
            res=res/i*(i-1);
            while(a%i==0) a/=i;  
        }  
    }  
    if(a>1) res=res/a*(a-1);  
    return res;  
} 

int main() {
	scanf("%d",&n);
	for(int d=1;d<=n;d++) 
		ans+=euler(d)*(n/d)*(n/d);
	printf("%lld",ans);
	return 0;
}
