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
	inline bool operator <(node b)const{
		return w>b.w;
	}
	inline bool operator >(node b)const{
		return w<b.w;
	}
};
void make_node(int x,int w){node ret; ret.x=x; ret.w=w; return ret;}
priority_queue <node> heap;
bool vis[maxn];
void Dijkstra(int s){
	memset(dist,0x7f,sizeof(dist));
	memset(vis,0,sizeof(vis));
	while (!heap.empty()) heap.pop();
	dist[s]=0;vis[s]=true;
	for (int i=lnk[s];i;i=nxt[i]) if (to[i]!=s) dist[to[i]]=min(dist[to[i]],w[i]),heap.push(make_node(to[i],dist[to[i]]));
	for (int i=1;i<n && !heap.empty();i++){
		node now=heap.top(); heap.pop();
		while ((!heap.empty()) && (vis[now.x] || dist[now.x]<now.w)) now=heap.top(),heap.pop();
		if (heap.empty() && (vis[now.x] || dist[now.x]<now.w)) break;
		vis[now.x]=true;
		for (int j=lnk[now.x];j;j=nxt[j])
			if (vis[to[j]]==false && dist[now.x]+w[j]<dist[to[j]])
				dist[to[j]]=dist[now.x]+w[j],heap.push(make_node(to[j],dist[to[j]]));
	}
}
