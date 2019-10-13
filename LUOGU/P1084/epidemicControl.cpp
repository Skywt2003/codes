#include<bits/stdc++.h>
#define int long long

using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=50005,maxe=100005;

int n,m;
int tot=0,lnk[maxn],nxt[maxe],to[maxe],w[maxe];
int army[maxn];

int fa[maxn][25],dist[maxn][25],deep[maxn];
bool vis[maxn],need[maxn];

int L=0,R=0,ans=-1;

vector<pair<int,int> > vec;
vector<int> left_time,need_time;

#define mid (((R-L)>>1)+L)

void add_edge(int x,int y,int z){
    tot++; to[tot]=y; w[tot]=z;
    nxt[tot]=lnk[x]; lnk[x]=tot;
}

void pre_build(int x){
    for (int i=1;i<25;i++) fa[x][i]=fa[fa[x][i-1]][i-1],dist[x][i]=dist[x][i-1]+dist[fa[x][i-1]][i-1];
    for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=fa[x][0]){
        deep[to[i]]=deep[x]+1; fa[to[i]][0]=x; dist[to[i]][0]=w[i];
        pre_build(to[i]);
    }
}

bool find_leaf(int x){
    if (vis[x]) return false;
    if (nxt[lnk[x]]==0) return true;
    for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=fa[x][0]){
        if (find_leaf(to[i])) return true;
    }
    return false;
}

bool compare_first(pair<int,int> aa,pair<int,int> bb){
    return aa.first < bb.first;
}

bool check(int x){
    memset(vis,0,sizeof(vis)),memset(need,0,sizeof(need));
    vec.clear(); left_time.clear(),need_time.clear();

    // Mova up and store free armies
    for (int i=1;i<=m;i++){
        int now=army[i],sum=0;
        for (int j=24;j>=0;j--) if (fa[now][j]>1 && sum+dist[now][j]<=x)
            sum+=dist[now][j],now=fa[now][j];
        if (fa[now][0]==1 && sum+dist[now][0]<=x) vec.push_back(make_pair(x-sum-dist[now][0],now));
        else vis[now]=true;
    }

    //Find whether an army is needed for a son
    for (int i=lnk[1];i;i=nxt[i]) need[to[i]]=find_leaf(to[i]);

    // (Pre) Make answer
    sort(vec.begin(),vec.end(),compare_first);
    for (int i=0;i<vec.size();i++)
        if (vec[i].first < dist[vec[i].second][0] && need[vec[i].second]) need[vec[i].second]=false;
        else left_time.push_back(vec[i].first);
    for (int i=lnk[1];i;i=nxt[i]) if (need[to[i]]) need_time.push_back(dist[to[i]][0]);
    
    // (Final) GREEDILY MAKE ANSWER!
    if (left_time.size() < need_time.size()) return false;
    sort(left_time.begin(),left_time.end());
    sort(need_time.begin(),need_time.end());
    int i=0,j=0;
    while (i<need_time.size() && j<left_time.size()){
        if (need_time[i] <= left_time[j]) i++,j++; else j++;
    }
    return i>=need_time.size();
}

signed main(){
    n=read();
    for (int i=1;i<n;i++){
        int x=read(),y=read(),z=read();
        add_edge(x,y,z),add_edge(y,x,z);
        R+=z;
    }
    m=read();
    for (int i=1;i<=m;i++) army[i]=read();

    deep[1]=1; pre_build(1);

    while (L<=R){
        if (check(mid)) ans=mid,R=mid-1;
        else L=mid+1;
    }

    printf("%lld\n",ans);
    return 0;
}