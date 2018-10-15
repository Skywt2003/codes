#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=100005;
int n,m,tot=0,lnk[maxn],nxt[maxn*2],son[maxn*2],ans=0;
bool vis[maxn];
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
inline void add(int x,int y){
	tot++;son[tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}
inline void spread(int x){
	vis[x]=true;
	for (int i=lnk[x];i;i=nxt[i]) if (vis[son[i]]==false) spread(son[i]);
}
int main(){
	n=read();m=read();
	for (int i=1;i<=m;i++){
		int x=read(),y=read();
		add(x,y);add(y,x);
	}
	memset(vis,0,sizeof(vis));
	for (int i=1;i<=n;i++) if (vis[i]==false) ans++,spread(i);
	printf("%d\n",ans);
	return 0;
}
