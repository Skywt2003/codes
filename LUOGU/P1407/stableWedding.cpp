#include<bits/stdc++.h>

#define int long long

using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=8005,maxe=48005;

int idx=0;
map<string,int> id;

int n,m;

int tot=0,lnk[maxn],nxt[maxe],to[maxe];
pair<int,int> wed[maxn];

void add_edge(int x,int y){
	tot++; to[tot]=y;
	nxt[tot]=lnk[x]; lnk[x]=tot;
}

int dfn[maxn],low[maxn];

stack<int> stk;
int cnt=0,blt[maxn];
vector<int> inc[maxn];

bool vis[maxn];

void tarjan(int x){
	vis[x]=true; dfn[x]=low[x]=++dfn[0];
	stk.push(x);
	for (int i=lnk[x];i;i=nxt[i]) if (!dfn[to[i]]){
		tarjan(to[i]);
		low[x]=min(low[x],low[to[i]]);
	} else if (vis[to[i]]) low[x]=min(low[x],dfn[to[i]]);
	if (dfn[x] == low[x]){
		for (;;){
			int now=stk.top(); stk.pop();
			vis[now]=false;
			blt[now]=x;inc[x].push_back(now);
			if (now==x) break;
		}
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for (int i=1;i<=n;i++){
		string a,b; cin>>a>>b;
		id[a]=++idx; id[b]=++idx;
		add_edge(id[a],id[b]);
		wed[i]=make_pair(id[a],id[b]);
	}
	cin>>m;
	for (int i=1;i<=m;i++){
		string a,b; cin>>a>>b;
		add_edge(id[b],id[a]);
	}

	for (int i=1;i<=2*n;i++) if (!dfn[i]) tarjan(i);

	for (int i=1;i<=n;i++)
		cout<<((blt[wed[i].first] == blt[wed[i].second] && blt[wed[i].first] && blt[wed[i].second])?"Unsafe":"Safe")<<endl;
	return 0;
}