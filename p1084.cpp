#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long LL;
const int N = 5e5+10;
const int sz = 16;

int n,m,x,y,loc[N],cnt; 
LL Max,ans,z;
int tot,point[N],nxt[N*2],v[N*2]; 
LL c[N*2];
int f[N][sz+5]; 
LL s[N][sz+5];
bool vis[N],leaf,has_res[N];
struct hp {
    int pt,lastp; LL ti,leftime;
    bool ctr;
}goal[N],res[N],save[N];

inline void addedge(int x,int y,LL z) {
    nxt[++tot]=point[x]; point[x]=tot; v[tot]=y; c[tot]=z;
    nxt[++tot]=point[y]; point[y]=tot; v[tot]=x; c[tot]=z;
}

inline void build(int x,int fa,int dep) {
    for (int i=1;i<sz;++i) {
        f[x][i]=f[f[x][i-1]][i-1];
        s[x][i]=s[f[x][i-1]][i-1]+s[x][i-1];
    }
    for (int i=point[x];i;i=nxt[i])
        if (v[i]!=fa) {
            f[v[i]][0]=x;
            s[v[i]][0]=c[i];
            build(v[i],x,dep+1);
        }
}

inline hp multi(int x,LL len) {
    hp re;
    LL sum=0;
    for (int i=sz-1;i>=0;--i)
        while (sum+s[x][i]<=len&&f[x][i]&&f[x][i]!=1)
            sum+=s[x][i],x=f[x][i];
    if (f[x][0]==1&&sum+s[x][0]<=len) {
    	re.pt=1;
    	re.lastp=x;
    	re.ti=sum+s[x][0];
    	re.ctr=true;
    	re.leftime=len-re.ti;
    }
    else {
    	re.pt=x;
    	re.lastp=0;
    	re.ti=sum;
    	re.ctr=false;
    	re.leftime=0;
	}
    return re;
}

inline void dfs(int x,int fa) {
    if (vis[x]) return;
    bool flag=false;
    for (int i=point[x];i;i=nxt[i])
        if (v[i]!=fa) {
            flag=true;
            dfs(v[i],x);
        }
    if (!flag) leaf=false;
}

inline int cmp(hp a,hp b) {
    return a.leftime<b.leftime;
}

inline bool check(LL t) {
    int rcnt=0,scnt=0;
    memset(vis,0,sizeof(vis));
    for (int i=1;i<=m;++i) {
        goal[i]=multi(loc[i],t);
        if (goal[i].ctr==false) 
        	vis[goal[i].pt]=true;
        else 
        	save[++scnt]=goal[i];
    }

    memset(has_res,0,sizeof(has_res));
    for (int i=point[1];i;i=nxt[i])
        if (v[i]) {
            leaf=true;
            if (!vis[v[i]]) 
            	dfs(v[i],1);
            if (!leaf) {
            	res[++rcnt].pt=v[i];
            	res[rcnt].leftime=c[i];
            }
            else 
            	has_res[v[i]]=true;
        }
    if (scnt<rcnt) 
    	return false;
    sort(save+1,save+scnt+1,cmp);
    sort(res+1,res+rcnt+1,cmp);
    int rnow=1,snow=1;
    while (rnow<=rcnt) {
        if (has_res[res[rnow].pt]) {
            rnow++;
            continue;
        }
        if (snow>scnt) return false;
        if (snow<=scnt&&!has_res[save[snow].lastp]) {
            has_res[save[snow].lastp]=true;
            snow++;
            continue;
        }
        if (snow<=scnt&&save[snow].leftime<res[rnow].leftime) 
        	snow++;
        else {
            has_res[res[rnow].pt]=true;
            rnow++;
            snow++;
        }
    }
    return true;
}

inline LL find() {
    LL l=0,r=Max,mid,ans=0;
    while (l<=r) {
        mid=(l+r)>>1;
        if (check(mid)) ans=mid,r=mid-1;
        else l=mid+1;
    }
    return ans;
}

int main() {
    scanf("%d",&n);
    for (int i=1;i<n;++i) {
        scanf("%d%d%lld",&x,&y,&z);
        addedge(x,y,z);
        Max+=z;
    }
    scanf("%d",&m);
    for (int i=1;i<=m;++i) 
    	scanf("%d",&loc[i]);
    for (int i=point[1];i;i=nxt[i])
        if (v[i]) 
        	++cnt;
    if (cnt>m) {
        puts("-1");
        return 0;
    }
    build(1,0,1);
    ans=find();
    printf("%lld\n",ans);
    return 0;
}
