#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1505;
int n;
int tot=0,lnk[maxn],nxt[maxn*2],son[maxn*2],fa[maxn];

inline void add_edge(int x,int y){
	tot++;son[tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}

struct point{
	int x,y;
};

point a[maxn];
point s;

void build_tree(int x){
	for (int i=lnk[x];i;i=nxt[i]) if (son[i]!=fa[x]) fa[son[i]]=x,build_tree(son[i]);
}

signed main(){
	n=read();
	for (int i=1;i<n;i++){
		int x=read(),y=read();
		add_edge(x,y);
	}
	build_tree(1);
	s.y=1e9;
	for (int i=1;i<=n;i++){
		a[i].x=read(),a[i].y=read();
		if (a[i].y<s.y) s=a[i];
	}
	
}