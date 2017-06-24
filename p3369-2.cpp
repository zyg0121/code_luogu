#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXL=100005;
const int INF=2147480000;

class Splay 
{
    #define root e[0].right   
    private:
        class node
        {
            public:
                int v,father; 
                int left,right; 
                int sum;
                int recy;
        };
        node e[MAXL];
        int n,points;
        void connect(int x,int f,int &son)
        {
            e[x].father=f;
            son=x;
            e[f].sum=e[e[f].left].sum+e[e[f].right].sum+e[f].recy;
            e[0].sum=0;
        }
        void zig(int x) 
        {
            int y=e[x].father;
            int mroot=e[y].father;
            int B=e[x].right;
            int &son=e[mroot].left==y?e[mroot].left:e[mroot].right;
            connect(B,y,e[y].left);connect(y,x,e[x].right);connect(x,mroot,son);
        }
        void zag(int x) 
        {
            int y=e[x].father;
            int mroot=e[y].father;
            int B=e[x].left;
            int &son=e[mroot].left==y?e[mroot].left:e[mroot].right;
            connect(B,y,e[y].right);connect(y,x,e[x].left);connect(x,mroot,son);
        }
        void splay(int at,int to)
        {
            to=e[to].father;
            while(e[at].father!=to)
            {
                if(e[e[at].father].right==at) zag(at);
                else zig(at);
            }
        }
        int crepoint(int v,int father)
        {
            n++;
            e[n]=(node){v,father,0,0,1,1};
            return n;
        }
        void destroy(int x) 
        {
            e[x].v=e[x].left=e[x].right=e[x].sum=e[x].father=e[x].recy=0;
            if(x==n) n--;
        }
    public:
        int getroot(){return root;}
        int find(int v)
        {
            int now=root;
            while(true)
            {
                if(e[now].v==v)
                {
                    splay(now,root);
                    return now;
                }
                if(v<=e[now].v)
                {
                    if(!e[now].left) return 0;
                    now=e[now].left;
                }
                else
                {
                    if(!e[now].right) return 0;
                    now=e[now].right;
                }
            }
        }
        int build(int v)
        {
            points++;
            if(n==0)
            {
                root=1;
                crepoint(v,0);
            }
            else
            {
                int now=root;
                while(true)
                {
                    e[now].sum++;
                    if(v==e[now].v)
                    {
                        e[now].recy++;
                        return now;
                    }
                    if(v<e[now].v)
                    {
                        if(!e[now].left)
                        {
                            crepoint(v,now);
                            e[now].left=n;
                            return n;
                        }
                        now=e[now].left;
                    }
                    else
                    {
                        if(!e[now].right)
                        {
                            crepoint(v,now);
                            e[now].right=n;
                            return n;
                        }
                        now=e[now].right;
                    }
                }
            }
            return 0;
        }
        void push(int v)
        {
            int add=build(v);
            splay(add,root);
        }
        void pop(int v)
        {
            int deal=find(v);
            if(!deal) return;
            points--;
            if(e[deal].recy>1)
            {
                e[deal].recy--;
                e[deal].sum--;
                return;
            }
            if(!e[root].left)
            {
                root=e[root].right;
                e[root].father=0;
            }
            else
            {
                int lef=e[root].left;
                while(e[lef].right) lef=e[lef].right;
                splay(lef,e[root].left);
                int rig=e[deal].right;
                connect(rig,lef,e[lef].right);connect(lef,0,root);
            }
            destroy(deal);
        }
        int rank(int v)
        {
            int ans=0,now=root;
            while(true)
            {
                if(e[now].v==v) return ans+e[e[now].left].sum+1;
                if(now==0) return 0;
                if(v<e[now].v) now=e[now].left;
                else
                {
                    ans=ans+e[e[now].left].sum+e[now].recy;
                    now=e[now].right;
                }
            }
            if(now) splay(now,root);
            return 0;
        }
        int atrank(int x)
        {
            if(x>points) return -INF;
            int now=root;
            while(true)
            {
                int minused=e[now].sum-e[e[now].right].sum;
                if(x>e[e[now].left].sum&&x<=minused) break;
                if(x<minused) now=e[now].left;
                else
                {
                    x=x-minused;
                    now=e[now].right;
                }
            }
            splay(now,root);
            return e[now].v;
        }
        int upper(int v)
        {
            int now=root;
            int result=INF;
            while(now)
            {
                if(e[now].v>v&&e[now].v<result) result=e[now].v;
                if(v<e[now].v) now=e[now].left;
                else now=e[now].right;
            }
            return result;
        }
        int lower(int v)
        {
            int now=root;
            int result=-INF;
            while(now)
            {
                if(e[now].v<v&&e[now].v>result) result=e[now].v;
                if(v>e[now].v) now=e[now].right;
                else now=e[now].left;
            }
            return result;
        }
    #undef root
};
Splay F;
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int opt,value;
        cin>>opt>>value;
        switch(opt)
        {
            case 1:
                F.push(value);
                break;
            case 2:
                F.pop(value);
                break;
            case 3:
                cout<<F.rank(value)<<endl;
                break;
            case 4:
                cout<<F.atrank(value)<<endl;
                break;
            case 5:
                cout<<F.lower(value)<<endl;
                break;
            case 6:
                cout<<F.upper(value)<<endl;
                break;
        }
    }
    return 0;
}
