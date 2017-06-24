#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 10
using namespace std;  
struct Node  
{  
    int x,y;  
};  

int getdist(int x,int y)  
{  
    return (x/3)*3+(y/3);  
}

const int Index[N][N]=  
{  
	{6,6,6,6,6,6,6,6,6},
	{6,7,7,7,7,7,7,7,6},
	{6,7,8,8,8,8,8,7,6},
	{6,7,8,9,9,9,8,7,6},
	{6,7,8,9,10,9,8,7,6},
	{6,7,8,9,9,9,8,7,6},
	{6,7,8,8,8,8,8,7,6},
	{6,7,7,7,7,7,7,7,6},
	{6,6,6,6,6,6,6,6,6}
};  
bool line[N][N],list[N][N],dist[N][N];
int data[N][N],tmp[N][N],Cnt,Ans;

Node getnext()
{  
    Node tmp;
    int min,t;
    tmp.x=N;
    tmp.y=N;
    min=N;
    for (int i=0;i<9;i++)
        for (int j=0;j<9;j++)
            if (!data[i][j])
            {
                t=0;
                for (int k=1;k<=9;k++)
                    if (!line[i][k])
                        if (!list[k][j])
                            if (!dist[getdist(i,j)][k])
								t++;
                if (t<min)
                {  
                    min=t;
                    tmp.x=i;
                    tmp.y=j;
                }
            }
    return tmp;
}

int getans()
{  
    int tmp;
    tmp=0;
    for (int i=0;i<9;i++)
        for (int j=0;j<9;j++) tmp+=Index[i][j]*data[i][j];
    return tmp;
}  

void change(int x,int y,int k)
{
    data[x][y]^=k;
    line[x][k]^=1;
    list[k][y]^=1;
    dist[getdist(x,y)][k]^=1;
}  

void solve(int k)  
{  
    if (k>Cnt)  
    {  
        Ans=max(Ans,getans());  
        return;  
    }  
    Node tmp;  
    tmp=getnext();  
    if (tmp.x==N && tmp.y==N) return;  
    for (int i=1;i<=9;i++)
        if (!line[tmp.x][i])
            if (!list[i][tmp.y])
                if (!dist[getdist(tmp.x,tmp.y)][i])
                {  
                    change(tmp.x,tmp.y,i);
                    solve(k+1);
                    change(tmp.x,tmp.y,i);
                }
    return;
}  

int main()  
{  
    memset(line,0,sizeof(line));
    memset(list,0,sizeof(list));
    memset(dist,0,sizeof(dist));
    Cnt=(N-1)*(N-1);
    for (int i=0;i<9;i++)
        for (int j=0;j<9;j++)
        {  
            scanf("%d",&data[i][j]);
            if (data[i][j])
            {  
                Cnt--;
                line[i][data[i][j]]=true;
                list[data[i][j]][j]=true;
                dist[getdist(i,j)][data[i][j]]=true;
            }  
        }  
    Ans=-1;
    solve(1);
    printf("%d\n",Ans);
    return 0;  
}  
