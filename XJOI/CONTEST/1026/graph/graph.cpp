#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;
#define int long long

const int maxn=2005,maxe=4005;
int n,m,L;
int c[maxn],dst[maxn][maxn];
int tot=0,lnk[maxn],nxt[maxe],son[maxe],w[maxe];
int ans=0;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();};
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

inline void add(int x,int y,int z){
	tot++;son[tot]=y;w[tot]=z;
	nxt[tot]=lnk[x];lnk[x]=tot;
}

namespace MyMath{
	inline int abs(int x){
		return x<0?-x:x;
	}
}

namespace Graph{
	queue<int> que;
	bool vis[maxn];

	inline void init(int s){
		while (!que.empty()) que.pop();
		memset(vis,0,sizeof(vis));
		memset(dst[s],0x3f,sizeof(dst[s]));
		dst[s][s]=0;
	}

	inline void SPFA(int s){
		init(s);
		que.push(s);
		while (!que.empty()){
			int head=que.front();que.pop();
			vis[head]=false;
			for (int i=lnk[head];i;i=nxt[i]) if (max(w[i],dst[s][head]) < dst[s][son[i]]){
				dst[s][son[i]]=max(w[i],dst[s][head]);
				if (!vis[son[i]]) que.push(son[i]),vis[son[i]]=true;
			}
		}
	}
}

signed main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	n=read();m=read();L=read();
	for (int i=1;i<=n;i++) c[i]=read();
	for (int i=1;i<=m;i++){
		int x=read(),y=read(),z=read();
		add(x,y,z);add(y,x,z);
	}
	for (int i=1;i<=n;i++) Graph::SPFA(i);
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			if (MyMath::abs(c[i]-c[j])>=L) ans+=dst[i][j];
	printf("%lld\n",ans);
	return 0;
}