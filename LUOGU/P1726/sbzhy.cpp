#include<bits/stdc++.h>
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int INF=1<<30;
const int maxn=5005,maxe=100005;

int n,e;
int tot=0,lnk[maxn],nxt[maxe],to[maxe];

void add_edge(int x,int y){
    tot++;to[tot]=y;
    nxt[tot]=lnk[x];lnk[x]=tot;
}

int low[maxn],dfn[maxn];
int cnt=0;
int stk[maxn],stk_top=0;
bool vis[maxn];
int blt[maxn];
vector<int> inc[maxn];

void tarjan(int x){
    low[x]=dfn[x]=++cnt;
    stk[++stk_top]=x; vis[x]=true;
    for (int i=lnk[x];i;i=nxt[i]) if (!dfn[to[i]]){
        tarjan(to[i]);
        low[x]=min(low[x],low[to[i]]);
    } else if (vis[to[i]]) low[x]=min(low[x],low[to[i]]);

    if (dfn[x]==low[x]){
        for (;;){
            int now=stk[stk_top]; stk_top--;
            blt[now]=x; vis[now]=false;
            inc[x].push_back(now);
            if (now==x) break;
        }
    }
}

bool operator <(vector<int> aa,vector<int> bb){
    if ((int)aa.size() != (int)bb.size()) printf("ERROR: compare vector not same size\b");
    for (int i=0;i<(int)aa.size();i++){
        if (aa[i]<bb[i]) return true;
        if (aa[i]>bb[i]) return false;
    }
    return false;
}

signed main(){
    freopen("testdata.in","r",stdin);
    freopen("my.out","w",stdout);
    n=read();e=read();
    for (int i=1;i<=e;i++){
        int x=read(),y=read(),type=read();
        add_edge(x,y);
        if (type==2) add_edge(y,x);
    }

    for (int i=1;i<=n;i++) if (blt[i]==0) tarjan(i);

    int max_num=0;
    for (int i=1;i<=n;i++) if (blt[i]==i) max_num=max(max_num,(int)inc[i].size());
    vector<int> ans; ans.clear();
    for (int i=0;i<max_num;i++) ans.push_back(INF);
    for (int i=1;i<=n;i++) if (blt[i]==i && (int)inc[i].size()==max_num){
        vector<int> now=inc[i];
        sort(now.begin(),now.end());
        if (now<ans) ans=now;
    }
    printf("%d\n",max_num);
    for (int i=0;i<(int)ans.size();i++) printf("%d ",ans[i]);
    printf("\n");
    return 0;
}