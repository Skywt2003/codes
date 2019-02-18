#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1e6+5,maxe=2*maxn;
int n,m,f[maxn];

int tot=0,lnk[maxn],nxt[maxe],to[maxe];
bool vis[maxn];

void add_edge(int x,int y){
	tot++;to[tot]=y;
	nxt[tot]=lnk[x];lnk[x]=tot;
}

void DFS(int x){
	if (vis[x]) return;
	vis[x]=true;
	for (int i=lnk[x];i;i=nxt[i]) if (!vis[to[i]]) DFS(to[i]);
}

signed main(){
	n=read();m=read();
	for (int i=1;i<=m;i++){
		int x=read(),y=read();
		if (x==y){
			f[x]++;
			continue;   
		}
		f[x]++;f[y]++;
		add_edge(x,y);add_edge(y,x);
	}
	DFS(1);
	for (int i=1;i<=n;i++) if (!vis[i]){
		printf("0\n");
		return 0;
	}
	int ans=0;
	for (int i=1;i<=n;i++) if (f[i]>=2){
		ans+=f[i]*(f[i]-1)/2;
	}
	printf("%lld\n",ans);
	return 0;
}