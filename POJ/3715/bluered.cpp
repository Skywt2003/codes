#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

#define int long long
using namespace std;

const int maxn=205,maxm=40005;

int T,n,m;
int tot=0,lnk[maxn],nxt[maxm],son[maxm];

struct Graph{
	bool vis[maxn];
	int con_x[maxn],con_y[maxn];

	inline void add_edge(int x,int y){
		tot++;son[tot]=y;
		nxt[tot]=lnk[x];lnk[x]=tot;
	}

	inline bool DFS(int x){
		for (int i=lnk[x];i;i=nxt[i]) if (!vis[son[i]]){
			int t=son[i];vis[t]=true;
			if ((con_y[t]==-1) || (DFS(t))){
				con_x[x]=t;
				con_y[t]=x;
				return true;
			}
		}
		return false;
	}

	inline int max_match(){
		memset(con_x,-1,sizeof(con_x));
		memset(con_y,-1,sizeof(con_y));
		int ret=0;
		for (int i=0;i<n;i++) if (!vis[i]) ret+=DFS(i);
		return ret;
	}
};

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

signed main(){
	T=read();
	while (T--){
		Graph::init();
		n=read();m=read();
		for (int i=0;i<n;i++) a[i]=read();
		for (int i=0;i<m;i++){
			int x=read(),y=read();
			Graph::add_edge(x,y);
			Graph::add_edge(y,x);
		}
	}
}