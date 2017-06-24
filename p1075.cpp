#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int n;

int main() {
	scanf("%d",&n);
	for(int i=2;i<=(int)sqrt(n);i++) {
		if(n%i==0) {
			cout<<n/i<<endl;
			return 0;
		}
	}
	return 0;
}
