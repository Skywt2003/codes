#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=100005;
int n,m,cnt=0,f[maxn][24];
int tot=0,lnk[maxn],nxt[2*maxn],son[2*maxn],fa[maxn],deep[maxn];
bool vis[maxn];
struct PathInfo{
	int root,x,y;
}a[maxn];
inline void add(int x,int y){
	tot++;son[tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}
inline void BuildTree(int x){
	vis[x]=true;
	for (int i=lnk[x];i;i=nxt[i]) if (!vis[son[i]]){
		fa[son[i]]=x;deep[son[i]]=deep[x]+1;
		BuildTree(son[i]);
	}
}
inline void BuildLCA(){
	for (int i=1;i<=n;i++) f[i][0]=fa[i];
	for (int j=1;j<=23;j++)
	for (int i=1;i<=n;i++)
		f[i][j]=f[f[i][j-1]][j-1];
}
inline int GetLCA(int x,int y){
	if (deep[x]<deep[y]) swap(x,y);
	for (int j=23;j>=0;j--) if (deep[f[x][j]]>=deep[y]) x=f[x][j];
	if (x==y) return x;
	for (int j=23;j>=0;j--) if (f[x][j]!=f[y][j]) x=f[x][j],y=f[y][j];
	return f[x][0];
}
inline bool CheckLCA(int x,int y,int root){
	while (x!=root){
		if (vis[x]) return false;
		x=fa[x];
	}
	while (y!=root){
		if (vis[y]) return false;
		y=fa[y];
	}
	if (vis[root]) return false;
	return true;
}
inline void ChangeLCA(int x,int y,int root){
	while (x!=root){
		vis[x]=true;x=fa[x];
	}
	while (y!=root){
		vis[y]=true;y=fa[y];
	}
	vis[root]=true;
}
inline bool cmp(PathInfo aa,PathInfo bb){
	return deep[aa.root]>deep[bb.root];
}
inline void init(){
	cnt=tot=0;
	memset(deep,0,sizeof(deep));
	memset(vis,0,sizeof(vis));
	memset(lnk,0,sizeof(lnk));
	memset(son,0,sizeof(son));
	memset(nxt,0,sizeof(nxt));
	memset(fa,0,sizeof(fa));
	memset(f,0,sizeof(f));
	memset(a,0,sizeof(a));
}
int main(){
	while (scanf("%d%d",&n,&m)!=-1){
		init();
		for (int i=1;i<n;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			add(x,y);add(y,x);
		}
		for (int i=1;i<=m;i++) scanf("%d%d",&a[i].x,&a[i].y);
		deep[1]=1;
		BuildTree(1);
		BuildLCA();
		for (int i=1;i<=m;i++) a[i].root=GetLCA(a[i].x,a[i].y);
		sort(a+1,a+1+m,cmp);
		memset(vis,0,sizeof(vis));
		for (int i=1;i<=m;i++){
			if (!CheckLCA(a[i].x,a[i].y,a[i].root)) continue;
			cnt++;
			ChangeLCA(a[i].x,a[i].y,a[i].root);
		}
		printf("%d\n",cnt);
	}
	return 0;
}