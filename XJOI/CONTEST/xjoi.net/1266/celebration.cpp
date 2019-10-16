#include<bits/stdc++.h>
// #define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1005;

int n,m;
int w[maxn];

int tot=0,lnk[maxn],nxt[maxn*2],to[maxn*2];

void add_edge(int x,int y){
	tot++; to[tot]=y;
	nxt[tot]=lnk[x]; lnk[x]=tot;
}

bool avl[maxn];
int now[maxn];

void DFS(int x,int fa,int t){
	if (x==t){
		for (int i=1;i<=now[0];i++) avl[now[i]]=false;
		return;
	}
	for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=fa){
		now[++now[0]]=to[i];
		DFS(to[i],x,t);
		now[0]--;
	}
}

void dismiss(int x,int y){
	memset(now,0,sizeof(now));
	memset(avl,1,sizeof(avl));
	now[++now[0]]=x; DFS(x,-1,y);
}

bool check(int x){
	for (int i=0;i<n;i++) if ((x&(1<<i)) && avl[i]==false) return false;
	return true;
}

signed main(){
	n=read(); m=read();
	for (int i=1;i<n;i++){
		int x=read()-1,y=read()-1;
		add_edge(x,y); add_edge(y,x);
	}
	for (int i=0;i<n;i++) w[i]=read();

	while (m--){
		int x=read()-1,y=read()-1,z=read();
		dismiss(x,y);
		int ans=0;
		for (int i=0;i<(1<<n);i++) if (check(i)){
			int now=0;
			for (int j=0;j<n;j++) if (i&(1<<j)) now^=w[j];
			ans+=(now==z);
		}
		printf("%d\n",ans);
	}
	return 0;
}