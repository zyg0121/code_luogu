#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int n,m,sum;

int main(){
	cin>>n>>m;
	for(int i=n;i<=m;i++) {
		if((i%2!=0) or (i%4==0)) 
			sum++;
	}
	cout<<sum<<endl;
	return 0;
}
