// F**KING UNAC!!!!!!

#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

#define int long long

#define write(_) cout<<#_<<" = "<<_<<endl

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
	bool vis[maxn];
	int loop[maxn*2],loop_cnt=0,loop_length=0;
	int dst[maxn*2];
	bool flg=false; // 是否找到了环

	inline void DFS(int x,int fa){
		if (vis[x]) return;
		vis[x]=true;
		if (flg) return;
		for (int i=lnk[x];i;i=nxt[i]) if (son[i]!=fa){
			if (flg) return;
			loop_cnt++;
			loop[loop_cnt]=son[i];dst[loop_cnt]=dst[loop_cnt-1]+w[i];
			if (vis[son[i]]) {flg=true;return;}
			DFS(son[i],x);
			if (flg) return;
			loop_cnt--;
		}
		vis[x]=false;
	}

	inline void find_loop(){
		memset(vis,0,sizeof(vis));
		for (int i=1;i<=n;i++) if (!flg) loop_cnt=0,DFS(i,-1); else break;
		int delta=dst[1];
		// loop_cnt--;
		// for (int i=1;i<=loop_cnt;i++) printf("%lld ",loop[i]);printf("\n");
		// for (int i=1;i<=loop_cnt;i++) printf("%lld ",dst[i]); printf("\n");
		in_loop[loop[1]]=true;
		for (int i=2;i<=loop_cnt;i++) in_loop[loop[i]]=true,dst[i]-=dst[1];dst[1]=0;
		// write(loop_cnt);
		// write(flg);
		loop_length=dst[loop_cnt]+delta;
		int tmp=loop_cnt;
		for (int i=1;i<=tmp;i++){
			loop_cnt++;
			loop[loop_cnt]=loop[i];
			dst[loop_cnt]=dst[i]+loop_length;
		}
	}

	int que[maxn*2];
	int head=0,tail=0;
	inline int make_answer(){
		int ret=0;
		if (loop_cnt<=0){
			for (int i=1;i<=n;i++) ret=max(ret,max_length[i]);
			return ret;
		}

		// write(loop_length);
		head=tail=0;
		que[++tail]=loop[1];
		for (int i=2;i<=loop_cnt;i++){
			while (head+1<=tail && dst[i]-dst[head] > (loop_length)/2) head++;
			while (head+1<=tail && max_length[que[head]]-dst[head] < max_length[que[head+1]]-dst[head+1]) head++;
			ret=max(ret,max_length[que[head]]+max_length[loop[i]] + dst[i]-dst[head]);
			que[++tail]=loop[i];
		}
		return ret;
	}
}

namespace tree{
	bool vis[maxn];

	inline void init(){
		memset(vis,0,sizeof(vis));
	}

	inline pair<int,int> DFS(int x,int fa){
		pair<int,int> ret;
		ret=make_pair(x,0);
		for (int i=lnk[x];i;i=nxt[i]) if (son[i]!=fa && in_loop[son[i]]==false){
			pair<int,int> now=DFS(son[i],x);
			now.second+=w[i];
			if (now.second+w[i]>ret.second) ret=now;
		}
		return ret;
	}

	inline int find_max_length(int x){
		in_loop[x]=false;
		pair<int,int> p=DFS(x,-1);
		pair<int,int> p2=DFS(p.first,-1);
		in_loop[x]=true;
		ans=max(ans,p2.second);
		return p.second;
	}
}

signed main(){
	// freopen("darksoul.in","r",stdin);
	// freopen("darksoul.out","w",stdout);
	n=read();
	for (int i=1;i<=n;i++){
		int x=read(),y=read(),z=read();
		add(x,y,z);add(y,x,z);
	}
	graph::find_loop();
	for (int i=1;i<=n;i++)
		if (in_loop[i]) max_length[i]=tree::find_max_length(i);
	// for (int i=1;i<=n;i++) if (in_loop[i]) printf("max_length[%lld]=%lld\n",i,max_length[i]);
	ans=max(ans,graph::make_answer());
	printf("%lld\n",ans);
	return 0;
}
