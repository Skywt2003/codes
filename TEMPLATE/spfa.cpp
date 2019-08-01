// 181019
// 190801 Update

#include<bits/stdc++.h>
using namespace std;

const int maxn=1005,maxe=10005;
int tot=0,lnk[maxn],nxt[maxe],to[maxe],w[maxe];
int dist[maxn];

bool vis[maxn];
queue <int> que;

void SPFA(int s){
	while (!que.empty()) que.pop();
	memset(dist,63,sizeof(dist));
	memset(vis,0,sizeof(vis));

	que.push(s); vis[s]=true; dist[s]=0;
	while (!que.empty()){
		int head=que.front(); que.pop();
		vis[head]=false;
		for (int i=lnk[head];i;i=nxt[i]) if (dist[head]+w[i] < dist[to[i]]){
			dist[to[i]]=dist[head]+w[i];
			if (!vis[to[i]]) que.push(to[i]),vis[to[i]]=true;
		}
	}
}
