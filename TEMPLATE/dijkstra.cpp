// 181109

#include<bits/stdc++.h>

const int maxn=1005,maxe=10005;
int tot=0,lnk[maxn],nxt[maxe],son[maxe],w[maxe];
int dst[maxn];

namespace Dijkstra{
	priority_queue<pair<int,int> > heap;
	
	inline void Dijkstra(int s){
		memset(dst,0x3f,sizeof(dst));
		dst[s]=0;
		for (int i=lnk[x];i;i=nxt[i]) if (w[i]<dst[son[i]]) dst[son[i]]=w[i],heap.push_back(make_pair(w[i],i));
		for (int i=1;i<n;i++){
			
		}
	}
}