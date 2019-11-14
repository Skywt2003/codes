#include<bits/stdc++.h>

#define int long long

inline int read()
{
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1e4+5,maxe=1e5+5;

int n,m;

int v[maxn];
int tot=0,lnk[maxn],nxt[maxe],to[maxe];

void add_edge(int x,int y)
{
	tot++; to[tot]=y;
	nxt[tot]=lnk[x];lnk[x]=tot;
}

int dfn[maxn],low[maxn],cnt=0;
bool vis[maxn];

int cnts=0;
std::stack<int> stk;
std::vector<int> inc[maxn];
int blt[maxn],val[maxn];

void tarjan(int x)
{
	dfn[x]=low[x]=++cnt; vis[x]=true; stk.push(x);
	for (int i=lnk[x];i;i=nxt[i]) if (!dfn[to[i]])
	{
		tarjan(to[i]);
		low[x]=std::min(low[x],low[to[i]]);
	}
	else if (vis[to[i]]) low[x]=std::min(low[x],low[to[i]]);

	if (low[x]==dfn[x]){
		cnts++;
		for (;;)
		{
			int now=stk.top(); stk.pop();
			inc[cnts].push_back(now);val[cnts]+=v[now];
			blt[now]=cnts; vis[now]=false;
			if (now==x) break;
		}
	}
}

int f[maxn],ind[maxn];
std::queue<int> que;

void fix(int &x,int y){x=std::max(x,y);}

void Topology()
{
	while (!que.empty()) que.pop();

	for (int i=1;i<=n;i++)
		for (int j=lnk[i];j;j=nxt[j])
			if (blt[to[j]] != blt[i]) ind[blt[to[j]]]++;
	for (int i=1;i<=cnts;i++) if (ind[i]==0) que.push(i),vis[i]=true,f[i]=val[i];

	while (!que.empty())
	{
		int head=que.front(); que.pop();
		for (int i=0;i<inc[head].size();i++)
			for (int j=lnk[inc[head][i]];j;j=nxt[j]) if (blt[to[j]] != head)
			{
				fix(f[blt[to[j]]],f[head]+val[blt[to[j]]]);
				ind[blt[to[j]]]--;
				if (ind[blt[to[j]]] == 0) que.push(blt[to[j]]);
			}
	}
}

signed main()
{
	#ifdef DEBUG
		freopen("testdata.in","r",stdin);
	#endif
	n=read(); m=read();
	for (int i=1;i<=n;i++) v[i]=read();
	for (int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		add_edge(x,y);
	}

	for (int i=1;i<=n;i++) if (!dfn[i]) tarjan(i);

	#ifdef DEBUG
	for (int i=1;i<=cnts;i++){
		printf("block #%lld: \n ",i);
		for (int j=0;j<inc[i].size();j++) printf("%lld ",inc[i][j]);
		printf("\n");
	}
	#endif

	Topology();

	int ans=0;
	for (int i=1;i<=cnts;i++) ans=std::max(ans,f[i]);
	printf("%lld\n",ans);

	return 0;
}