#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int size = 100000+10;
const int INF = 2147480000;
#define WHILE for(;;)

struct Splay {
    #define root e[0].ch[1]
    struct node {
	int v,father;
	int ch[2];
	int sum;
	int recy;
    };
    node e[size];
    int n,points;
    void update(int x) {//更新当前值
	e[x].sum=e[e[x].ch[0]].sum+e[e[x].ch[1]].sum+e[x].recy;
    }
    int identify(int x) {//获取父子关系
	return e[e[x].father].ch[0]==x ? 0 : 1;
    }
    void connect(int x,int f,int son) {//建立父子关系
	e[x].father=f;
	e[f].ch[son]=x;
    }
    void rotate(int x) {//旋转，根据^操作来自动判断左右旋
	int y=e[x].father;
	int mroot=e[y].father;
	int mrootson=identify(y);
	int yson=identify(x);
	int B=e[x].ch[yson^1];
	connect(B,y,yson);connect(y,x,(yson^1));connect(x,mroot,mrootson);
	update(y);update(x);
    }
    void splay(int at,int to) {//旋转操作
	to=e[to].father;
	while(e[at].father!=to) {
	    int up=e[at].father;
	    if(e[up].father==to) rotate(at);
	    else if(identify(up)==identify(at)) {
		rotate(up);
		rotate(at);
	    }
	    else {
		rotate(at);
		rotate(at);
	    }
	}
    }
    int crepoint(int v,int father) {//添加节点
	n++;
	e[n].v=v;
	e[n].father=father;
	e[n].sum=e[n].recy=1;
	return n;
    }
    void destory(int x) {//摧毁节点
	e[x].v=e[x].ch[0]=e[x].ch[1]=e[x].sum=e[x].recy=0;
	if(x==n) n--;
    }
//public:
    int getroot() {return root;}
    int find(int v) {//查找操作
	int now=root;
	WHILE {
	    if(e[now].v==v) {
		splay(now,root);
		return now;
	    }
	    int nxt=v<e[now].v?0:1;
	    if(!e[now].ch[nxt]) return 0;
	    now=e[now].ch[nxt];
	}
    }
    int build(int v) {//建树操作
	points++;
	if(n==0) {
	    root=1;
	    crepoint(v,0);
	}
	else {
	    int now=root;
	WHILE {
	    e[now].sum++;
	    if(v==e[now].v) {
		e[now].recy++;
		return now;
	    }
	    int nxt=v<e[now].v?0:1;
	    if(!e[now].ch[nxt]) {
		crepoint(v,now);
		e[now].ch[nxt]=n;
		return n;
	    }
	    now=e[now].ch[nxt];
	}
        }
	return 0;
    }
    void push(int v) {//插入操作
	int add=build(v);
	splay(add,root);
    }
    void pop(int v) {//删除节点
	int deal=find(v);
	if(!deal) return ;
	points--;
	if(e[deal].recy>1) {
	    e[deal].recy--;
	    e[deal].sum--;
	    return ;
	}
	if(!e[deal].ch[0]) {
	    root=e[deal].ch[1];
	    e[root].father=0;
	}
	else {
	    int lef=e[deal].ch[0];
	    while(e[lef].ch[1]) lef=e[lef].ch[1];
	    splay(lef,e[deal].ch[0]);
	    int rig=e[deal].ch[1];
	    connect(rig,lef,1);
	    connect(lef,0,1);
	    update(lef);
	}
	destory(deal);
    }
    int rank(int v) {//获取排名(值为v的元素在这棵树⾥是第⼏⼩)
	int ans=0,now=root;
	WHILE {
	    if(e[now].v==v) return ans+e[e[now].ch[0]].sum+1;
	    if(now==0) return 0;
	    if(v<e[now].v) now=e[now].ch[0];
	    else {
		ans=ans+e[e[now].ch[0]].sum+e[now].recy;
		now=e[now].ch[1];
	    }
	}
	if(now) splay(now,root);
	return 0;
    }
    int atrank(int x) {//rank的反操作
	if(x>points) return -INF;
	int now=root;
	WHILE {
	    int minused=e[now].sum-e[e[now].ch[1]].sum;
	    if(x>e[e[now].ch[0]].sum and x<=minused) break;
	    if(x<minused) now=e[now].ch[0];
	    else {
		x=x-minused;
		now=e[now].ch[1];
	    }
	}
	splay(now,root);
	return e[now].v;
    }
    int upper(int v) {//寻找前驱(该值对应的一个最近的上界值)
	int now=root;
	int result=INF;
	while(now) {
	    if(e[now].v>v and e[now].v<result) result=e[now].v;
	    if(v<e[now].v) now=e[now].ch[0];
	    else now=e[now].ch[1];
	}
	return result;
    }
    int lower(int v) {//寻找后继
	int now=root;
	int result=-INF;
	while(now) {
	    if(e[now].v<v and e[now].v>result) result=e[now].v;
	    if(v>e[now].v) now=e[now].ch[1];
	    else now=e[now].ch[0];
	}
	return result;
    }
    #undef root
}Tree;

int main() {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
	int opt,value;
	scanf("%d%d",&opt,&value);
	switch(opt) {
	case 1:
	    Tree.push(value);
	    break;
	case 2:
	    Tree.pop(value);
	    break;
	case 3:
	    printf("%d\n",Tree.rank(value));
	    break;
	case 4:
	    printf("%d\n",Tree.atrank(value));
	    break;
	case 5:
	    printf("%d\n",Tree.lower(value));
	    break;
	case 6:
	    printf("%d\n",Tree.upper(value));
	    break;
	}
    }
    return 0;
}
