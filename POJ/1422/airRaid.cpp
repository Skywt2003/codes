#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

// #define int long long

using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=250,maxe=16005;

int T,n,m;
int tot=0,lnk[maxn],nxt[maxe],to[maxe];

void clear_graph(){
	tot=0;
	memset(lnk,0,sizeof(lnk));
	memset(nxt,0,sizeof(nxt));
	memset(to,0,sizeof(to));
}

void add_edge(int x,int y){
	tot++; to[tot]=y;
	nxt[tot]=lnk[x];lnk[x]=tot;
}

int con_x[maxn],con_y[maxn];
bool vis[maxn];

bool DFS(int x){
	for (int i=lnk[x];i;i=nxt[i]) if (!vis[to[i]]){
		vis[to[i]]=true;
		if (con_y[to[i]]==-1 || DFS(con_y[to[i]])){
			con_x[x]=to[i];con_y[to[i]]=x;
			return true;
		}
	}
	return false;
}

int max_match(){
	int ret=0;
	memset(con_x,-1,sizeof(con_x));
	memset(con_y,-1,sizeof(con_y));

	for (int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		ret+=DFS(i);
	}
	return ret;
}

signed main(){
	T=read();
	while (T--){
		clear_graph();

		n=read(),m=read();
		for (int i=1;i<=m;i++){
			int x=read(),y=read();
			add_edge(x,y+n);
		}
		for (int i=1;i<=n;i++) add_edge(i+n,i);

		printf("%d\n",n-max_match());
	}
	return 0;
}