#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=1005;
int n,s,t,tot=0,lnk[maxn],son[maxn*2],nxt[maxn*2],ans=-1,vis[maxn];
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
inline void add(int x,int y){
	tot++;son[tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}
inline void DFS(int x,int step){
	if (x==t){
		ans=step;return;
	}
	if (ans!=-1) return;
	vis[x]=true;
	for (int i=lnk[x];i;i=nxt[i]) if (vis[son[i]]==false) DFS(son[i],step+1);
}
int main(){
	n=read();
	for (int i=1;i<n;i++){
		int x=read(),y=read();
		add(x,y);add(y,x);
	}
	s=read(),t=read();
	memset(vis,0,sizeof(vis));
	DFS(s,0);
	printf("%d\n",ans);
	return 0;
}
