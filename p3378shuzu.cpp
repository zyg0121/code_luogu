#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

const int maxn=1000010;
int n,heaps;
int heap[maxn];

void put(int d)
{
	int now,next;
	heap[++heaps]=d;
	now=heaps;
	while(now>1)
	{
		next=now/2;
		if(heap[now]>=heap[next])
			return;
		swap(heap[now],heap[next]);
		now=next;
	}
}

int get()
{
	int now,next,res;
	res=heap[1];
	heap[1]=heap[heaps--];
	now=1;
	while(now*2<=heaps)
	{
		next=now*2;
		if(next<heaps and heap[next+1]<heap[next])
			next++;
		if(heap[now]<=heap[next])
			return res;
		swap(heap[now],heap[next]);
		now=next;
	}
	return res;
}

int main()
{
	scanf("%d",&n);
	int x,y;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(x==1)
		{
			scanf("%d",&y);
			put(y);
			continue;
		}
		if(x==2)
		{
			printf("%d\n",heap[0]);
			continue;
		}
		if(x==3)
		{
			get();
			continue;
		}
	}
	return 0;
}
