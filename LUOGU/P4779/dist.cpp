#include<bits/stdc++.h>
// #define int long long
using namespace std;

const int maxn=10005,maxe=500005;
const int INF=0x7f7f7f7f,CANNOT=2147483647;
int n,m,s;
int tot=0,lnk[maxn],nxt[maxe],son[maxe],w[maxe];
int dst[maxn];

namespace Dijkstra{
	struct node{
		int x,w;

		inline bool operator <(node b)const{
			return w>b.w;
		}
		inline bool operator >(node b)const{
			return w<b.w;
		}
	};
	priority_queue <node> heap;
	bool vis[maxn];

	inline void Dijkstra(int s){
		memset(dst,0x7f,sizeof(dst));
		memset(vis,0,sizeof(vis));
		while (!heap.empty()) heap.pop();
		dst[s]=0;vis[s]=true;
		for (int i=lnk[s];i;i=nxt[i]) if (son[i]!=s) dst[son[i]]=min(dst[son[i]],w[i]),heap.push((node){son[i],dst[son[i]]});
		for (int i=1;i<n;i++){
			if (heap.empty()) break;
			node now=heap.top();heap.pop();
			while ((!heap.empty()) && (vis[now.x] || dst[now.x]<now.w)) now=heap.top(),heap.pop();
			if (heap.empty() && (vis[now.x] || dst[now.x]<now.w)) break;
			vis[now.x]=true;
			for (int j=lnk[now.x];j;j=nxt[j]) if (vis[son[j]]==false && dst[now.x]+w[j]<dst[son[j]]) dst[son[j]]=dst[now.x]+w[j],heap.push((node){son[j],dst[son[j]]});
		}
	}
}

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

inline void add_edge(int x,int y,int z){
	tot++;son[tot]=y;w[tot]=z;
	nxt[tot]=lnk[x];lnk[x]=tot;
}

signed main(){
	n=read(),m=read(),s=read();
	for (int i=1;i<=m;i++){
		int x=read(),y=read(),z=read();
		add_edge(x,y,z);
		// add_edge(y,x,z);
	}
	Dijkstra::Dijkstra(s);
	for (int i=1;i<=n;i++) printf("%d ",(dst[i]==INF)?CANNOT:dst[i]);
	printf("\n");
	return 0;
}