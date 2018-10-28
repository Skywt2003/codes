#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
#define CLEAR(_) memset(_,0,sizeof(_))
#define CLEAR_REG(_) memset(_,-1,sizeof(_))
#define CLEAR_MAX(_) memset(_,0x3f,sizeof(_))
#define CLAER_MIN(_) memset(_,0x80,sizeof(_))

const int maxn=405,maxe=160005;
int T,n,m,vis[maxn],con_x[maxn],con_y[maxn];
int tot=0,lnk[maxn],nxt[maxe],son[maxe];

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
inline void init(){
	tot=0;CLEAR(lnk);CLEAR(nxt);CLEAR(son);
	CLEAR_REG(con_x);CLEAR_REG(con_y);
}
inline void add(int x,int y){
	tot++;son[tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}
inline bool DFS(int s){
	for (int i=lnk[s];i;i=nxt[i]) if (!vis[son[i]]){
		int t=son[i];vis[t]=true;
		if ((con_y[t]==-1)||(DFS(con_y[t]))){
			con_x[s]=t;
			con_y[t]=s;
			return true;
		}
	}
	return false;
}
inline int max_match(){
	int ret=0;
	for (int i=1;i<=n;i++) CLEAR(vis),ret+=DFS(i);
	return ret;
}
int main(){
	T=read();
	while (T--){
		init();
		n=read();m=read();
		for (int i=1;i<=n;i++){
			int num=read();
			for (int j=1;j<=num;j++){
				int x=read();
				add(i,x+n);add(x+n,i);
			}
		}
		int now=max_match();
		printf(now==n?"YES\n":"NO\n");
	}
	return 0;
}