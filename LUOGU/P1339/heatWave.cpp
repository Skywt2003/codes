#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=2505,maxe=6205*2;

int n,e,s,t;

int tot=0,lnk[maxn],nxt[maxe],to[maxe],w[maxe];
int dist[maxn];

void add_edge(int x,int y,int z){
    tot++;to[tot]=y;w[tot]=z;
    nxt[tot]=lnk[x];lnk[x]=tot;
}

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

signed main(){
    n=read();e=read();s=read();t=read();
    for (int i=1;i<=e;i++){
        int x=read(),y=read(),z=read();
        add_edge(x,y,z);add_edge(y,x,z);
    }

    SPFA(s);
    printf("%lld\n",dist[t]);
    return 0;
}