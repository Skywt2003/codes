// 181019

#include<bits/stdc++.h>

const int maxn=1005,maxe=10005;
int tot=0,lnk[maxn],nxt[maxe],son[maxe],w[maxe];
int dst[maxn];

namespace SPFA{
	bool vis[maxn];
	queue <int> que;

	inline void SPFA(int s){
		memset(vis,0,sizeof(vis));
		while (!que.empty()) que.pop();
		que.push(s);vis[s]=true;
		while (!que.empty()){
			int head=que.front();que.pop();
			vis[head]=false;
			for (int i=lnk[head];i;i=nxt[i]) if (dst[head]+w[i]<dst[son[i]]){
				dst[son[i]]=dst[head]+w[i];
				if (!vis[son[i]]) que.push(son[i]),vis[son[i]]=true;
			}
		}
	}
}