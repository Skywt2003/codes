#include<bits/stdc++.h>

#define int long long
#define clear(_) memset(_,0,sizeof(_));

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=2005,maxe=6005;

int T;
int n,m;
int tot=0,lnk[maxn],nxt[maxe],to[maxe],w[maxe];
int f[maxn];

bool vis[maxn];
int dist[maxn];
std::queue<int> que;

void init()
{
	tot=0;
	clear(lnk);clear(nxt);
	clear(to);clear(w);
}

void add_edge(int x,int y,int z)
{
	tot++; to[tot]=y; w[tot]=z;
	nxt[tot]=lnk[x]; lnk[x]=tot;
}

bool find_minus_loop(int s) // SPFA
{
	while (!que.empty()) que.pop();
	memset(dist,0x3f,sizeof(dist));
	clear(vis); clear(f);

	dist[s]=0,vis[s]=true; f[s]++; que.push(s);
	while (!que.empty())
	{
		int head=que.front(); que.pop(); vis[head]=false;
		for (int i=lnk[head];i;i=nxt[i]) if (dist[head]+w[i] < dist[to[i]])
		{
			dist[to[i]]=dist[head]+w[i];
			if (!vis[to[i]])
			{
				f[to[i]]++; if (f[to[i]] > n) return true;
				vis[to[i]]=true,que.push(to[i]);
			}
		}
	}
	return false;
}

signed main()
{
	T=read();
	while (T--)
	{
		init();

		n=read();m=read();
		for (int i=1;i<=m;i++)
		{
			int x=read(),y=read(),z=read();
			add_edge(x,y,z);
			if (z>=0) add_edge(y,x,z);
		}
		
		if (find_minus_loop(1)) printf("YE5\n"); else printf("N0\n");
	}
	return 0;
}