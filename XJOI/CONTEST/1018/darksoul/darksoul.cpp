#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

#define int long long

const int maxn=1000005,maxe=2000005;
int n,ans=0;
int tot=0,lnk[maxn],nxt[maxe],son[maxe],w[maxe];
int INF;

int max_length[maxn];
bool in_loop[maxn];

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

inline void add(int x,int y,int z){
	tot++;son[tot]=y,w[tot]=z;
	nxt[tot]=lnk[x];lnk[x]=tot;
}

namespace graph{
	bool vis[maxn],fa[maxn],all_loop=0;

	inline void find_loop(){
		memset(vis,0,sizeof(vis));
		queue <int> que;
		while (!que.empty()) que.pop();
		que.push(1);fa[1]=-1;vis[1]=true;
		while (!que.empty()){
			int head=que.front();que.pop();
			vis[head]=false;
			for (int i=lnk[head];i;i=nxt[i]) if (son[i]!=fa[head]){
				if (vis[son[i]]){
					while (!que.empty()) in_loop[que.front()]=true,all_loop++,que.pop();
					return;
				}
				fa[son[i]]=head;
				vis[son[i]]=true;que.push(son[i]);
			}
		}
	}

	int head=0,tail=0;
	int que[maxn];
	int dst[maxn];

	inline int make_answer(){
		int ret=0;
		int s=-1;
		for (int i=1;i<=n;i++) if (in_loop[i]) {s=i;break;}
		if (s==-1){
			for (int i=1;i<=n;i++) ret=max(ret,max_length[i]);
			return ret;
		}
		make_loop_dist(s);
		int lst=-1,now=s;
		dst[s]=0;
		do{
			for (int i=lnk[now];i;i=nxt[i]) if (in_loop[son[i]] && son[i]!=lst){
				lst=now;now=son[i];
				dst[now]=dst[lst]+w[i];
				break;
			}
		} while(now!=s);
		
	}
}

namespace tree{
	bool vis[maxn];

	inline void init(){
		memset(vis,0,sizeof(vis));
	}

	inline pair<int,int> DFS(int x,int fa){
		pair<int,int> ret;
		ret=make_pair(-1,0);
		for (int i=lnk[x];i;i=nxt[i]) if (son[i]!=fa && in_loop[son[i]]==false){
			pair<int,int> now=DFS(son[i]);
			now.second+=w[i];
			if (now.second+w[i]>ret.second) ret=now;
		}
		return ret;
	}

	inline int find_max(int s){ // IT'S NO USE!!!
		init();
		pair<int,int> p1=DFS(s,-1);
		init();
		pair<int,int> p2=DFS(p1.first,-1);
		return p2.second;
	}

	inline int find_max_length(int x){
		pair<int,int> p=DFS(x,-1);
		return p.second;
	}
}

signed main(){
	freopen("darksoul.in","r",stdin);
	freopen("darksoul.out","w",stdout);
	n=read();
	for (int i=1;i<=n;i++){
		int x=read(),y=read(),z=read();
		add(x,y,z);add(y,x,z);
	}
	graph::find_loop();
	for (int i=1;i<=n;i++)
		if (in_loop[i]) max_length[i]=tree::find_max_length(i);
	ans=graph::make_answer();
	printf("%lld\n",ans);
	return 0;
}
