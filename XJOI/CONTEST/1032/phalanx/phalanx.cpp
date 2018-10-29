#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

#define int long long
using namespace std;

const int maxn=1005,maxm=4005;
int n,m;
int tot=0,lnk[maxn],nxt[2*maxm],son[2*maxm];

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

inline void add_edge(int x,int y){
	tot++;son[tot]=y;
	nxt[tot]=lnk[x];lnk[x]=tot;
}

int vis[maxn],con_x[maxn],con_y[maxn];

inline bool DFS(int s){
	for (int i=lnk[s];i;i=nxt[i]) if (!vis[son[i]]){
		int t=son[i];vis[t]=true;
		if ((con_y[t]==-1)||DFS(con_y[t])){
			con_x[s]=t;
			con_y[t]=s;
			return true;
		}
	}
	return false;
}

inline int max_match(){
	memset(con_x,-1,sizeof(con_x));
	memset(con_y,-1,sizeof(con_y));
	int ret=0;
	for (int i=1;i<=n;i++) memset(vis,0,sizeof(vis)),ret+=(bool)DFS(i);
	return ret;
}

signed main(){
	n=read();m=read();
	for (int i=1;i<=m;i++){
		int x=read(),y=read();
		add_edge(x,y);
	}
	printf("%lld\n",n*(2*n-max_match()));
	return 0;
}