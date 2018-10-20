#include<bits/stdc++.h>

#define int long long
using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=10005,maxe=20005;

int n,m,dst[maxn];
int tot=0,lnk[maxn],nxt[maxe],son[maxe];
int ans=1e8;
vector<int> anses;

inline void add(int x,int y){
	tot++;son[tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}

inline void DFS(int x,int fa){
	for (int i=lnk[x];i;i=nxt[i]) if (son[i]!=fa){
		dst[son[i]]=dst[x]+1;
		DFS(son[i],x);
	}
}

signed main(){
	n=read();m=read();
	for (int i=1;i<=m;i++){
		int x=read(),y=read();
		add(x,y);add(y,x);
	}
	for (int i=1;i<=n;i++){
		dst[i]=0;
		DFS(i,-1);
		int now=0;
		for (int j=1;j<=n;j++) now=max(now,dst[j]);
		if (now<ans){
			ans=now;
			anses.clear();
			anses.push_back(i);
		} else if (now==ans) anses.push_back(i);
	}
	for (int i=0;i<anses.size();i++) printf("%lld ",anses[i]);
	printf("\n");
	return 0;
}