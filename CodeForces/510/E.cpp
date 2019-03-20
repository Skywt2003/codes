#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int maxn=405,maxe=20005,maxv=2e4+5;
const int INF=1e9+7;

int n,a[maxn];
int s,t,ans=0;
int tot=-1,nxt[maxe],to[maxe],w[maxe],deep[maxn],lnk[maxn];

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

void add_edge(int x,int y,int z){
	tot++;to[tot]=y;w[tot]=z;nxt[tot]=lnk[x];lnk[x]=tot;
}

void add_flow_edge(int x,int y,int z){
	add_edge(x,y,z);add_edge(y,x,0);
}

namespace Flow{
	int que[maxn],cur[maxn];

	void init(){
		tot=-1;
		memset(lnk,-1,sizeof(lnk));
		memset(nxt,-1,sizeof(nxt));
	}

	bool BFS(){
		memset(deep,0,sizeof(deep));
		deep[s]=1;
		int head=0,tail=1;que[tail]=s;
		while (head!=tail){
			head++;
			for (int i=lnk[que[head]];i!=-1;i=nxt[i]){
				if (w[i]>0 && deep[to[i]]==0) deep[to[i]]=deep[que[head]]+1,que[++tail]=to[i];
			}
		}
		if (deep[t]==0) return false;
		return true;
	}

	int DFS(int x,int now){
		if (x==t) return now;
		for (int i=cur[x];i!=-1;i=cur[x]=nxt[i]) if (deep[to[i]]==deep[x]+1 && w[i]!=0){
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
		while (BFS()){
			for (int i=1;i<=n+2;i++) cur[i]=lnk[i];
			while (int now=DFS(s,INF)) ans+=now;
		}
	}
}

namespace mymath{
	int prime[maxv];

	void build_prime(int N){
		memset(prime,true,sizeof(prime));
		prime[1]=false;
		vector<int> vec;vec.clear();
		for (int i=2;i<=N;i++){
			if (prime[i]) vec.push_back(i);
			for (int j=0;j<(int)vec.size();j++){
				if (i*vec[j]>N) break;
				prime[i*vec[j]]=false;
				if (i%vec[j]==0) break;
			}
		}
	}
}

void build_edge(){
	s=n+1,t=n+2;
	for (int i=1;i<=n;i++) if (a[i]&1) add_flow_edge(s,i,2); else add_flow_edge(i,t,2);
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++){
			if ((a[i]&1) != (a[j]&1) && mymath::prime[a[i]+a[j]]){
				if (a[i]&1) add_flow_edge(i,j,1); else add_flow_edge(j,i,1);
			}
		}
}

vector<int> prt[maxn];
bool vis[maxn];
int cnt=0;

void DFS(int x,int now){
	prt[now].push_back(x);
	vis[x]=true;
	for (int i=lnk[x];i!=-1;i=nxt[i]) if (to[i]<=n && vis[to[i]]==false){
		if ((i&1)==0&&(w[i  ]==0)) DFS(to[i],now);
		if ((i&1)==1&&(w[i^1]==0)) DFS(to[i],now);
	}
}

signed main(){
	n=read();
	if (n&1){printf("Impossible\n");return 0;}
	for (int i=1;i<=n;i++) a[i]=read();

	mymath::build_prime(2e4);
	Flow::init();
	build_edge();

	Flow::Dinic();
	if (ans!=n){printf("Impossible\n");return 0;}

	for (int i=1;i<=n;i++) if (!vis[i]) DFS(i,++cnt);

	printf("%d\n",cnt);
	for (int i=1;i<=cnt;i++){
		printf("%d ",(int)prt[i].size());
		for (int j=0;j<(int)prt[i].size();j++) printf("%d ",prt[i][j]);
		printf("\n");
	}

	return 0;
}