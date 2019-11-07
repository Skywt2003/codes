#include<bits/stdc++.h>

#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=3005,maxe=4505;
const int INF=0x3f3f3f3f3f3f3f3f;

int n,m,s,t,d;
int tot=-1,lnk[maxn],nxt[2*maxe],to[2*maxe],w[2*maxe],ww[2*maxe],cur[maxn];
int deep[maxn];
int ans=0;
queue<int> que;


void add_edge(int x,int y,int z){
	tot++;to[tot]=y;w[tot]=ww[tot]=z;
	nxt[tot]=lnk[x];lnk[x]=tot;
}

bool BFS(){
	memset(deep,0,sizeof(deep));
	while (!que.empty()) que.pop();
	
	que.push(s);deep[s]=1;
	while (!que.empty()){
		int head=que.front(); que.pop();
		for (int i=lnk[head];i!=-1;i=nxt[i]) if (w[i]>0 && deep[to[i]]==0) deep[to[i]]=deep[head]+1,que.push(to[i]);
	}
	return deep[t];
}

int DFS(int x,int now){
	if (x==t) return now;
	for (int i=cur[x];i!=-1;i=cur[x]=nxt[i]) if (deep[to[i]]==deep[x]+1 && w[i]){
		int nxtd=DFS(to[i],min(now,w[i]));
		if (nxtd>0){
			w[i]-=nxtd;
			w[i^1]+=nxtd;
			return nxtd;
		}
	}
	return 0;
}

void Dinic(){
	for (int i=0;i<=tot;i++) w[i]=ww[i];
	while (BFS()){
		for (int i=1;i<=n;i++) cur[i]=lnk[i];
		while (int now=DFS(s,INF)) ans+=now;
	}
}

class uniset{
	private:
		int fa[maxn];
		
	public:
		void init(int n){
			for (int i=1;i<=n;i++) fa[i]=i;
		}
		
		int getfa(int x){
			return (fa[x]==x)?x:fa[x]=getfa(fa[x]);
		}
		
		void merge(int x,int y){
			x=getfa(x),y=getfa(y);
			if (x==y) return;
			fa[x]=y;
		}
};
uniset u;

signed main(){
	n=read();m=read();d=read();
	if (d==2 && n>200){
		u.init(n);
		for (int i=1;i<=m;i++){
			int x=read(),y=read();
			u.merge(x,y);
		}
		int ans=0;
		for (int i=1;i<=n;i++)
			for (int j=i+1;j<=n;j++)
				ans+=u.getfa(i)==u.getfa(j);
		printf("%lld\n",ans);
		return 0;
	}
	memset(lnk,-1,sizeof(lnk));
	memset(nxt,-1,sizeof(nxt));
	for (int i=1;i<=m;i++){
		int x=read(),y=read();
		add_edge(x,y,1);add_edge(y,x,1);
	}
	for (s=1;s<=n;s++)
		for (t=s+1;t<=n;t++) Dinic();
	printf("%lld\n",ans);
	return 0;
}
