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
	int vis[maxn],fa[maxn],dstfa[maxn],cnt=0;
	int loop[maxn*2],loop_cnt=0,loop_length=0;
	int dst[maxn*2];

	inline void get_loop(int x){
		vis[x]=++cnt;
		for (int i=lnk[x];i;i=nxt[i]) if (son[i]!=fa[x]){
			if (vis[son[i]]){
				if (vis[son[i]]<vis[x]) continue;
				int now=son[i];dstfa[x]=w[i];
				for (;;){
					loop[++loop_cnt]=now;
					dst[loop_cnt+1]=dst[loop_cnt]+dstfa[now];
					if (now==x) break;
					now=fa[now];
				}
			} else fa[son[i]]=x,dstfa[son[i]]=w[i],get_loop(son[i]);
		}
	}

/*
 * 非常麻烦的找环的函数 via http://www.cnblogs.com/widsom/p/9492725.html
 * need to build: loop[] loop_cnt loop_length in_loop[] dst[]
 */
	inline void find_loop(){
		memset(vis,0,sizeof(vis));
		cnt=0;loop_cnt=0;
		get_loop(1);
		loop_length=dst[loop_cnt+1];

		memset(in_loop,0,sizeof(in_loop));
		for (int i=1;i<=loop_cnt;i++) in_loop[loop[i]]=true;

		int tmp=loop_cnt; // 拓展倍长
		for (int i=1;i<=tmp;i++){
			loop[++loop_cnt]=loop[i];
			dst[loop_cnt+1]=dst[i+1]+loop_length;
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

		// for (int i=1;i<=loop_cnt;i++) printf("%3lld ",i);printf("\n");
		// for (int i=1;i<=loop_cnt;i++) printf("%3lld ",loop[i]);printf("\n");
		// for (int i=1;i<=loop_cnt;i++) printf("%3lld ",dst[i]);printf("\n");
		// for (int i=1;i<=loop_cnt;i++) printf("%3lld ",max_length[loop[i]]);printf("\n");
		// printf("\n");

		head=tail=1;
		que[tail]=1;
		for (int i=2;i<=loop_cnt;i++){
			while (head<=tail && (!(dst[i]-dst[que[head]] <= (loop_length)/2))) head++;
			while (head+1<=tail && max_length[loop[que[head]]]-dst[que[head]] < max_length[loop[que[head+1]]]-dst[que[head+1]]) head++;
			// printf("i=%lld head=%lld tail=%lld\n",i,head,tail);
			// if (head<=tail && dst[i]-dst[que[head]] <= (loop_length)/2) printf("now: %lld\n",max_length[loop[que[head]]]+max_length[loop[i]] + dst[i]-dst[que[head]]);
			if (head<=tail && dst[i]-dst[que[head]] <= (loop_length)/2) ret=max(ret,max_length[loop[que[head]]]+max_length[loop[i]] + dst[i]-dst[que[head]]);
			while (tail>=head && max_length[loop[que[tail]]]-dst[que[tail]] < max_length[loop[i]]-dst[i]) tail--;
			que[++tail]=i;
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
			pair<int,int> now;now=DFS(son[i],x);
			now.second+=w[i];
			if (now.second>ret.second) ret=now;
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
	n=read();
	for (int i=1;i<=n;i++){
		int x=read(),y=read(),z=read();
		add(x,y,z);add(y,x,z);
	}
	graph::find_loop();
	for (int i=1;i<=n;i++)
		if (in_loop[i]) max_length[i]=tree::find_max_length(i);
	// for (int i=1;i<=n;i++) if (in_loop[i]) printf("%lld max_length=%lld\n",i,max_length[i]);
	ans=max(ans,graph::make_answer());
	printf("%lld\n",ans);
	return 0;
}
