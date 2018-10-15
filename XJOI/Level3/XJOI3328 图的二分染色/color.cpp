#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=1005,maxm=1000005;
int n,m,tot=0,lnk[maxn],son[maxm],nxt[maxm],rmb[maxn];
bool vis[maxn],flg=true;
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
inline void add(int x,int y){
	tot++;son[tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}
inline void DFS(int x,int now){
	vis[x]=true;rmb[x]=now;
	for (int i=lnk[x];i;i=nxt[i]){
		if (vis[son[i]]==false) DFS(son[i],1-now); else
		if (rmb[son[i]]!=-1&&rmb[son[i]]==now){flg=false;return;}
	}
}
int main(){
	memset(rmb,-1,sizeof(rmb));
	n=read();m=read();
	for (int i=1;i<=m;i++){
		int x=read(),y=read();
		add(x,y);add(y,x);
	}
	memset(vis,0,sizeof(vis));
	for (int i=1;i<=n;i++) if (vis[i]==false){
		DFS(i,0);
		if (flg==false) break;
	}
	if (flg==true) printf("Yes\n"); else printf("No\n");
	return 0;
}

