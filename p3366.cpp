#include <cstdio> 
#include <algorithm> 
using namespace std;

#define MAXM 200000
#define MAXN 5000  

using namespace std; 

struct edge { 
    int u, v, w;  
} edges[MAXM]; 

int cmp (edge a, edge b) 
{ 
    return a.w < b.w; 
} 

int set[MAXN]; 

int findSet(int k) 
{ 
    return set[k] == k ? k : set[k] = findSet(set[k]); 
} 

int main() 
{ 
    int n, m, nos, wt = 0; 
    scanf("%d %d", &n, &m); 
    for (int k = 1; k <= m; k++) 
        scanf("%d %d %d", &edges[k].u, &edges[k].v, &edges[k].w); 
    sort(edges+1, edges+1+m, cmp); 
    for (int k = 1; k <= n; k++) 
        set[k] = k; 
    nos = n; 
    for (int k = 1; k <= m && nos > 1; k++) 
	{ 
        int fu = findSet(edges[k].u); 
        int fv = findSet(edges[k].v); 
        if (fu != fv)
		 { 
            set[fu] = fv; 
            wt += edges[k].w; 
            nos--; 
        } 
    }
    int fc = findSet(1);
    for (int k = 2; k <= n; k++) 
	{
        if (findSet(k) != fc) 
		{
            printf("orz");
            return 0;
        }
    }
    printf("%d", wt);   
    return 0; 
}
