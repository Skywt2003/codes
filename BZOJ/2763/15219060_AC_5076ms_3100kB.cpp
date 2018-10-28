#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
const int maxn=10005,maxe=100005,maxk=15;
int n,m,k,s,t,dst[maxn][maxk],INF;
int tot=0,lnk[maxn],nxt[maxe],son[maxe],w[maxe];
bool vis[maxn];
queue<int> que;
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
inline void add(int x,int y,int z){
	tot++;son[tot]=y,w[tot]=z;nxt[tot]=lnk[x];lnk[x]=tot;
}
inline void init(){
	memset(lnk,-1,sizeof(lnk));
	memset(nxt,-1,sizeof(nxt));
	memset(dst,0x3f,sizeof(dst));
	INF=dst[0][0];
}
inline void SPFA(){
	que.push(s);dst[s][0]=0;vis[s]=true;
	while (!que.empty()){
		int x=que.front();que.pop();vis[x]=false;
		for (int i=lnk[x];i!=-1;i=nxt[i])
			for (int j=0;j<=k;j++){
				if (dst[x][j]+w[i]<dst[son[i]][j]){
					dst[son[i]][j]=dst[x][j]+w[i];
					if (!vis[son[i]]) vis[son[i]]=true,que.push(son[i]);
				}
				if (j>0&&dst[x][j-1]<dst[son[i]][j]){
					dst[son[i]][j]=dst[x][j-1];
					if (!vis[son[i]]) vis[son[i]]=true,que.push(son[i]);
				}
			}
	}
}
int main(){
	init();
	n=read();m=read();k=read();
	s=read();t=read();
	for (int i=0;i<m;i++){
		int x=read(),y=read(),z=read();
		add(x,y,z);add(y,x,z);
	}
	SPFA();
	int ans=INF;
	for (int j=0;j<=k;j++) if (dst[t][j]<ans) ans=dst[t][j];
	printf("%d\n",ans);
	return 0;
}