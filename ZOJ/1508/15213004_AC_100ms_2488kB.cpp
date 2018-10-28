#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
const int maxn=50005,maxe=150005,INF=1e9;
int n,s,t,dst[maxn];
int tot=0,lnk[maxn],nxt[maxe],son[maxe],w[maxe];
bool vis[maxn];
queue<int> que;
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
inline void Init(){
	tot=0;
	s=INF;t=-INF;
	memset(lnk,-1,sizeof(lnk));
	memset(nxt,-1,sizeof(nxt));
	memset(son,-1,sizeof(son));
	memset(w,0,sizeof(w));
	memset(vis,0,sizeof(vis));
	memset(dst,0x80,sizeof(dst));
}
inline void add(int x,int y,int z){
	tot++;son[tot]=y;w[tot]=z;nxt[tot]=lnk[x];lnk[x]=tot;
	s=min(s,min(x,y));t=max(t,max(x,y));
}
inline void SPFA(){
	que.push(s);vis[s]=true;dst[s]=0;
	while (!que.empty()){
		int x=que.front();que.pop();vis[x]=false;
		for (int i=lnk[x];i!=-1;i=nxt[i]) if (dst[x]+w[i]>dst[son[i]]){
			dst[son[i]]=dst[x]+w[i];
			if (!vis[son[i]]) vis[son[i]]=true,que.push(son[i]);
		}
	}
}
int main(){
	while (scanf("%d",&n)!=-1){
		Init();
		for (int i=0;i<n;i++){
			int a=read(),b=read(),c=read();
			add(a-1,b,c);
		}
		for (int i=s+1;i<=t;i++) add(i,i-1,-1),add(i-1,i,0);
		SPFA();
		printf("%d\n",dst[t]);
	}
	return 0;
}