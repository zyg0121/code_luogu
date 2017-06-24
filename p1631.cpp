#include "cstdio"
#include "iostream"
#include "algorithm"
#include "queue"
#include "vector"
using namespace std;

typedef pair<int,int> pii;
const int size = 1e6+10;
int a[size],b[size],k[size];
int n;
priority_queue<pii,vector<pii >,greater<pii > >q;

int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) {
		scanf("%d",&b[i]);
		k[i]=1;
		q.push(make_pair(a[1]+b[i],i));
	}
	while(n--) {
		printf("%d ",q.top().first);
		int i=q.top().second;
		q.pop();
		q.push(make_pair(a[++k[i]]+b[i],i));
	}
	putchar('\n');
	return 0;
}
