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
	bool vis[maxn],fa[maxn];
	vector <int> loop;

	inline void find_loop(){
		memset(vis,0,sizeof(vis));loop.clear();
		queue <int> que;
		while (!que.empty()) que.pop();
		que.push(1);fa[1]=-1;vis[1]=true;
		while (!que.empty()){
			int head=que.front();que.pop();
			vis[head]=false;
			for (int i=lnk[head];i;i=nxt[i]) if (son[i]!=fa[head]){
				if (vis[son[i]]){
					while (!que.empty()) in_loop[que.front()]=true,loop.push_back(que.front()),que.pop();
					return;
				}
				fa[son[i]]=head;
				vis[son[i]]=true;que.push(son[i]);
			}
		}
	}

	inline void make_loop_dist(int s){

	}

	int que[maxn*2];
	int head=0,tail=0;
	inline int make_answer(){
		int ret=0;
		if (loop.size()==0){
			for (int i=1;i<=n;i++) ret=max(ret,max_length[i]);
			return ret;
		}
		make_loop_dist(s);
		for (int i=0;i<loop_cnt;i++) loop.push_back(loop[i]); // 复制一遍环，搞成两倍，方便处理

		que[++tail]=loop[0];
		for (int i=1;i<loop.size();i++){
			
		}
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
