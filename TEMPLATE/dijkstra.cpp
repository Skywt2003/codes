// 181109

#include<bits/stdc++.h>

const int maxn=1005,maxe=10005;
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