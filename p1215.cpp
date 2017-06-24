#include <cstdio>
#include <cstring>
#include <algorithm>

const int size = 100+10;
bool p[size];
bool q[size][size];
int a,b,c;

void dfs(int aa,int bb,int cc);
void ss(int,int,int);

int main() {
	scanf("%d%d%d",&a,&b,&c);
	dfs(0,0,c);
	for(int i=c-b;i<=c;i++)
		if(p[i]==true)
			printf("%d ",i);
	return 0;
}

void dfs(int aa,int bb,int cc) {
	if(aa==0 and p[cc]==false) p[cc]=true; 
    if(q[aa][bb]==true) return;  
    q[aa][bb]=true;
    if(cc>0 and aa<a) 
    	dfs(std::min(a,aa+cc),bb,std::max(0,cc+aa-a));
	if(cc>0 and bb<b) 
		dfs(aa,std::min(b,bb+cc),std::max(0,cc+bb-b));
	if(bb>0 and aa<a)
		dfs(std::min(a,aa+bb),std::max(0,bb+aa-a),cc);
	if(bb>0 and cc<c)
		dfs(std::min(a,aa+bb),std::max(0,bb+aa-a),cc);
    if(aa>0 and cc<c)
        dfs(std::max(0,aa+cc-c),bb,std::min(c,cc+aa));
    if(aa>0 and bb<b)
        dfs(std::max(0,aa+bb-b),std::min(b,bb+aa),cc);
}
