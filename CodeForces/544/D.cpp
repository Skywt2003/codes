#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=3005,maxe=6005;
int n,m;
int tot=0,lnk[maxn],nxt[maxe],son[maxe];
int dst[maxn][maxn];
int s1,t1,s2,t2,m1,m2;

inline void add_edge(int x,int y){
	tot++;son[tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}

queue <int> que;
bool vis[maxn];

inline void SPFA(int st){
	while (!que.empty()) que.pop();
	memset(vis,0,sizeof(vis));
	memset(dst[st],63,sizeof(dst[st]));
	que.push(st);vis[st]=true;dst[st][st]=0;
	while (!que.empty()){
		int head=que.front();que.pop();vis[head]=false;
		for (int i=lnk[head];i;i=nxt[i]) if (dst[st][head]+1<dst[st][son[i]]){
			dst[st][son[i]]=dst[st][head]+1;
			if (!vis[son[i]]) que.push(son[i]),vis[son[i]]=true;
		}
	}
}

signed main(){
	n=read();m=read();
	for (int i=1;i<=m;i++){
		int x=read(),y=read();
		add_edge(x,y);add_edge(y,x);
	}
	s1=read();t1=read();m1=read();
	s2=read();t2=read();m2=read();

	for (int i=1;i<=n;i++) SPFA(i);
	if (dst[s1][t1]>m1 || dst[s2][t2]>m2){
		printf("-1\n");
		return 0;
	}

	int ans=dst[s1][t1]+dst[s2][t2];
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if (dst[s1][i]+dst[i][j]+dst[j][t1]<=m1 && dst[s2][i]+dst[i][j]+dst[j][t2]<=m2){
				ans=min(ans,dst[s1][i]+dst[s2][i]+dst[i][j]+dst[j][t1]+dst[j][t2]);
			}
			if (dst[s1][j]+dst[j][i]+dst[i][t1]<=m1 && dst[s2][i]+dst[i][j]+dst[j][t2]<=m2){
				ans=min(ans,dst[s1][j]+dst[s2][i]+dst[i][j]+dst[i][t1]+dst[j][t2]);
			}
		}
	}
	printf("%lld\n",m-ans);
	return 0;
}