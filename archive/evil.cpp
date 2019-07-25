#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=100005,maxe=200005;
int n,m,d,INF;
bool isg[maxn];

int tot=0,lnk[maxn],nxt[maxe],to[maxe],fa[maxn];
int f[maxn],g[maxn];

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

void add_edge(int x,int y){
    tot++;to[tot]=y;
    nxt[tot]=lnk[x];lnk[x]=tot;
}

int getValueF(int x){
	if (f[x]==INF){
		if (isg[x]) return 0; else return INF;
	} else {
		if (isg[x]) return max((int)0,f[x]); else return f[x];
	}
}

int getValueG(int x){
	if (g[x]==INF){
		if (isg[x]) return 0; else return INF;
	} else {
		if (isg[x]) return max((int)0,g[x]); else return g[x];
	}
}

void buildFArr(int x){
    f[x]=0;
    for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=fa[x]) fa[to[i]]=x,buildFArr(to[i]);
    for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=fa[x] && (getValueF(to[i]))!=INF) f[x]=max(f[x],getValueF(to[i])+1);
    if (f[x]==0) f[x]=INF;
}

bool cmp(pair<int,int> aa,pair<int,int> bb){
	return aa.second>bb.second;
}

void buildGArr(int x){
    vector<pair<int,int> > vec; vec.clear();
    for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=fa[x] && (getValueF(to[i])!=INF)) vec.push_back(make_pair(to[i],getValueF(to[i])));
    vec.push_back(make_pair(0,-2));
    sort(vec.begin(),vec.end(),cmp);
    for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=fa[x]){
    	g[to[i]]=0;
    	if (getValueG(x)!=INF) g[to[i]]=max(g[to[i]],getValueG(x)+1);
		g[to[i]]=max(g[to[i]],((to[i]==vec[0].first)?vec[1].second:vec[0].second)+2);
		if (g[to[i]]==0) g[to[i]]=INF;
    }
    for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=fa[x]) buildGArr(to[i]);
}

signed main(){
    n=read();m=read();d=read();
    for (int i=1;i<=m;i++){
        int x=read();
        isg[x]=true;
    }
    for (int i=1;i<n;i++){
        int x=read(),y=read();
        add_edge(x,y);add_edge(y,x);
    }

    memset(f,63,sizeof(f));INF=f[0];
    buildFArr(1);

    memset(g,63,sizeof(g));
    buildGArr(1);

//	for (int i=1;i<=n;i++) printf("F[%lld] = %lld   G[%lld]=%lld\n",i,f[i],i,g[i]);

    int ans=0;
    for (int i=1;i<=n;i++){
    	int now=1;
    	if (f[i]!=INF && f[i]>d) now=0;
    	if (g[i]!=INF && g[i]>d) now=0;
    	ans+=now;
	}
    printf("%lld\n",ans);
    return 0;
}
