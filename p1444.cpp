#include <cstdio>
#include <cstring>
#include <algorithm>

const int maxx = 15;
int n,ans,nxt[maxx],worm_pair[maxx];
struct node {
	int x,y;
}a[maxx];

void build_edge() {
	int dis[maxx];
	memset(dis,-1,sizeof dis);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++) {
			if(a[i].y==a[j].y and a[j].x>a[i].x) {
				int _dis = a[j].x - a[i].x;
				if(dis[i]==-1 or dis[i]>_dis) {
					dis[i] = _dis;
					nxt[i] = j;
				}
			}
		}
}

bool pd() {
	for(int i=0;i<n;i++) {
		int pos = i;
		for(int j=0;j<n;j++) {
			pos = nxt[worm_pair[pos]];
			if(pos==-1) break;
		}
		if(pos!=-1) return true;
	}
	return false;
}

void make_worm_pair() {
	int i;
	for(i = 0; i < n; i++) {
		if(worm_pair[i] == -1) break;
	}
	if(i == n) {
		if(pd()) ans++;
		return;
	}		
	for(int j = i + 1; j < n; j++) {			
		if(worm_pair[j] != -1) continue;
		worm_pair[i] = j;
		worm_pair[j] = i;
		make_worm_pair();
		worm_pair[j] = -1;
	}
	worm_pair[i] = -1;
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) 
		scanf("%d%d", &a[i].x, &a[i].y);
	memset(nxt, -1 ,sizeof(nxt));
	build_edge();
	memset(worm_pair, -1 ,sizeof(worm_pair));
	make_worm_pair();
	printf("%d\n", ans);
	return 0;
}
