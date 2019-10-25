// 181109
// Updated 190801

#include<bits/stdc++.h>
using namespace std;
// #define int long long

const int maxn=1005,maxe=10005;
int tot=0,lnk[maxn],nxt[maxe],to[maxe],w[maxe];
int dist[maxn];

struct node{
	int x,w;
	inline bool operator <(node b)const{return w>b.w;}
	inline bool operator >(node b)const{return w<b.w;}
};

priority_queue <node> heap;
bool vis[maxn];

void Dijkstra(int s){
	memset(dist,63,sizeof(dist));
	memset(vis,0,sizeof(vis));
	while (!heap.empty()) heap.pop();

	dist[s]=0.0;
	heap.push((node){s,dist[s]});
	while (!heap.empty()){
		node now=heap.top(); heap.pop();
		if (vis[now.x]) continue;
		vis[now.x]=true;
		for (int i=lnk[now.x];i;i=nxt[i]) if (dist[now.x]+w[i]<dist[to[i]]){
			dist[to[i]]=dist[now.x]+w[i];
			if (!vis[to[i]]) heap.push((node){to[i],dist[to[i]]});
		}
	}
}