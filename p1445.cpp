#include <cstdio>
#include <iostream>
#include <cmath>
#include <map>
using namespace std;

typedef unsigned long long ULL;
ULL n,ans=1;
const long long mod = 1e9+7;
int prime[3500]= {2},P=1,N,Num;
map<int,int> divisor;
map<int,int>::iterator it;

ULL Add(ULL a,ULL b) {
	return (a+b) % mod;
}

ULL Mul(ULL a,ULL b) {
	ULL ans = 0;
	while( b ){
		if(b & 1) ans = Add(ans,a);
		a = Add(a,a);
		b >>= 1;
	}
	return ans;
}

int isPrime(int N) {
	if(N % 3==0)
		return N==3;
	for(int i=1; prime[i]*prime[i]<=N; ++i)
		if( N % prime[i]==0)
			return 0;
	return 1;
}

ULL divNum(int Num) {
	for(int i=0; prime[i]<=Num && i<P; ++i)
		while( Num % prime[i] == 0 ) {
			divisor[prime[i]]++;
			Num /= prime[i];
		}
	if(Num!=1) divisor[Num]=1;
	ULL result=1;
	for(it=divisor.begin(); it!=divisor.end(); ++it)
//		result = Mul(result,(it->second + 1));
		result *=( it->second + 1 );
	divisor.clear();
	return result;
}

int main() {
	for(int i=3; i<=31627; i+=2)
		if(isPrime(i)) prime[P++]=i;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) {
//		ans=Mul(ans,i);
		ans*=i;
	}
	ans=ans*ans;
	cout<<divNum(ans)<<endl;
	return 0;
}
