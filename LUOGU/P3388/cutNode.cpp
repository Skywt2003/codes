#include<bits/stdc++.h>

#define int long long

inline int read(){
	int ret=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=2e4+5,maxe=2e5+5;

int n,m;

int tot=0,lnk[maxn],nxt[maxe],to[maxe];

void add_edge(int x,int y)
{
	tot++; to[tot]=y;
	nxt[tot]=lnk[x];lnk[x]=tot;
}

int cnt=0;
int dfn[maxn],low[maxn];
bool ans[maxn];

void tarjan(int x,int from){
	dfn[x]=low[x]=++cnt;
	int nowson=0;
	for (int i=lnk[x];i;i=nxt[i])
	{
		if (!dfn[to[i]])
		{
			tarjan(to[i],from);
			low[x]=std::min(low[x],low[to[i]]);
			if (low[to[i]] >= dfn[x] && x!=from) ans[x]=true;
			if (x==from) nowson++;
		}
		low[x]=std::min(low[x],dfn[to[i]]);
	}
	if (x==from && nowson>=2) ans[x]=true;
}

signed main()
{
	n=read();m=read();
	for (int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		add_edge(x,y);add_edge(y,x);
	}

	for (int i=1;i<=n;i++) if (!dfn[i]) tarjan(i,i);

	int ans_cnt=0;
	for (int i=1;i<=n;i++) ans_cnt+=ans[i];
	printf("%lld\n",ans_cnt);
	for (int i=1;i<=n;i++) if (ans[i]) printf("%lld ",i);
	return 0;
}