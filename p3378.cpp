#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

priority_queue<int,vector<int>,greater<int> > pq;
int n,x,y;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(x==1)
		{
			scanf("%d",&y);
			pq.push(y);
			continue;
		}
		if(x==2)
		{
			printf("%d\n",pq.top());
			continue;
		}
		if(x==3)
		{
			pq.pop();
			continue;
		}
	}
	return 0;
}
