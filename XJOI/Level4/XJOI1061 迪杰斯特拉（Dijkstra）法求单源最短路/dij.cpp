#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
const int maxn=1005,maxe=2005;
int n,m,s,t,tot=0,lnk[maxn],son[maxe],nxt[maxe],w[maxe],fa[maxn],dst[maxn],ans[maxn];
bool vis[maxn];
//struct WT{
//	int x,id;
//};
//priority_queue <WT> heap;
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
inline void add(int x,int y,int z){
	tot++;son[tot]=y;w[tot]=z;nxt[tot]=lnk[x];lnk[x]=tot;
}
inline void Dijstra(){
	memset(dst,63,sizeof(dst));
	memset(vis,0,sizeof(vis));
	dst[s]=0;
	for (int i=1;i<=n;i++){
		int min=1<<30,k=-1;
		for (int j=1;j<=n;j++) if (vis[j]==false&&dst[j]<min) min=dst[j],k=j;
		if (k==-1) break;
		vis[k]=true;
		for (int j=lnk[k];j;j=nxt[j]) if ((vis[son[j]]==false)&&(dst[k]+w[j]<dst[son[j]])) dst[son[j]]=dst[k]+w[j],fa[son[j]]=k;
	}
}
int main(){
	s=read();t=read();
	n=read();m=read();
	for (int i=1;i<=m;i++){
		int x=read(),y=read(),z=read();
		add(x,y,z);add(y,x,z);
	}
	Dijstra();
	printf("%d\n",dst[t]);
	int now=t;
	while (now) ans[++ans[0]]=now,now=fa[now];
	for (int i=ans[0];i>1;i--) printf("%d ",ans[i]);printf("%d\n",ans[1]);
	return 0;
}
