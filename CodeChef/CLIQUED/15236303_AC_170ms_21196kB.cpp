#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
const int maxn=100005,maxe=400005;
int T,n,k,x,m,s,INF;
int tot=0,lnk[maxn],nxt[maxe],son[maxe],w[maxe];
long long dst[maxn];
bool vis[maxn];
queue<int> que;
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
inline void init(){
	tot=0;
	memset(vis,0,sizeof(vis));
	memset(dst,0x3f,sizeof(dst));INF=dst[0];
	memset(lnk,0,sizeof(lnk));
	memset(nxt,0,sizeof(nxt));
	memset(son,0,sizeof(son));
	memset(w,0,sizeof(w));
}
inline void add(int x,int y,int z){
	tot++;son[tot]=y;w[tot]=z;nxt[tot]=lnk[x];lnk[x]=tot;
}
inline void SPFA(){
	que.push(s);vis[s]=1;dst[s]=0;
	while (!que.empty()){
		int x=que.front();que.pop();vis[x]=false;
		for (int i=lnk[x];i;i=nxt[i]) if ((long long)dst[x]+w[i]<dst[son[i]]){
			dst[son[i]]=(long long)dst[x]+w[i];
			if (!vis[son[i]]) vis[son[i]]=1,que.push(son[i]);
		}
	}
}
int main(){
	T=read();
	while (T--){
		init();
		n=read();k=read();x=read();m=read();s=read();
		for (int i=1;i<=m;i++){
			int x=read(),y=read(),z=read();
			add(x,y,z);add(y,x,z);
		}
		for (int i=1;i<=k;i++) add(i,n+1,0),add(n+1,i,x);
		SPFA();
		for (int i=1;i<=n;i++) printf("%lld ",dst[i]);
		printf("\n");
	}
	return 0;
}