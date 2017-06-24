#include <bits/stdc++.h>
using namespace std;

char mid[20], aft[20];
void dfs(int ml, int mr, int al, int ar) 
{
    if (ml>mr||al>ar) 
	{
        return;
    }
    printf("%c", aft[ar]);
    for (int k = ml; k <= mr; k++) 
	{
        if (mid[k] == aft[ar]) 
		{
            dfs(ml, k-1, al, al+k-ml-1);
            dfs(k+1, mr, al+k-ml, ar-1);
            break; 
        }
    }
}
int main() 
{
    scanf("%s", mid);
    scanf("%s", aft);
    int len = strlen(mid) - 1;
    dfs(0, len, 0, len);
    return 0;    
}
