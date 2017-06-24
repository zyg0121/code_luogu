#include <cstdio>
#include <iostream>
#include <algorithm>

const int size = 125000+4;

bool a[size];
int n,m,limit,cnt;
bool flag;

inline void write(int re)
{
    if (re>9) write(re/10);
    putchar(re%10+'0');
}

int main() {
	freopen("p1214.in","r",stdin);
	freopen("p1214.out","w",stdout);
	scanf("%d%d",&n,&m);
	int p,q;
	for (p = 0; p <= m; p++ ) {
		for (q = 0; q <= m; q++ ) {
			a[q*q+p*p] = true;
		}
	}
	
	limit = 2*m*m;
	
/*
	公差的范围：i = 1->limit/(n-1);
	首项的范围：j = 0->j+(n-1)*i<=limit;
*/

	int i,j,k;
	for (i = 1; i <= limit/(n-1); i++ ) {
		for (j = 0; j+(n-1)*i<= limit; j++ ) {
			cnt = 0;
			for (k = j; k <= limit; k+=i ) {
				if ( a[k] == true )
					cnt++;
				else
					break;
				if ( cnt==n )
					break;
			}
			if( cnt==n ) {
				flag = true;
				write(j);putchar(' ');write(i);putchar(10);
			}
		}
	}

	if ( flag==false ) {
		puts("NONE");
	}
	return 0;
}
