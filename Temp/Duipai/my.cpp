#pragma GCC optmize(2)

#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

#ifdef DEBUG_MD
	#define debug(format, ...) fprintf(stderr, format, __VA_ARGS__)
#else
	#define debug(format, ...) 0
#endif

#define int long long
using namespace std;

const int maxn=205,maxm=40005;

int T,n,m,a[maxn];
int tot=0,lnk[maxn],nxt[maxm],son[maxm];
vector<int> v1,v2;

int now_block=-1;
bool blocked[maxn];

namespace Graph{
	bool vis[maxn];
	int con_x[maxn],con_y[maxn];
	int con_x_tmp[maxn],con_y_tmp[maxn];

	inline void add_edge(int x,int y){
		tot++;son[tot]=y;
		nxt[tot]=lnk[x];lnk[x]=tot;
	}

	inline void init(){
		tot=0;v1.clear();v2.clear();
		now_block=-1;
		memset(lnk,0,sizeof(lnk));
		memset(nxt,0,sizeof(nxt));
		memset(son,-1,sizeof(son));

		memset(blocked,0,sizeof(blocked));
	}

	inline bool DFS(int x){
		if (x==now_block) return false;
		if (blocked[x]) return false;
		for (int i=lnk[x];i;i=nxt[i]) if ((!vis[son[i]])&&(son[i]!=now_block)&&(!blocked[son[i]])){
			int t=son[i];vis[t]=true;
			if ((con_y[t]==-1) || (DFS(con_y[t]))){
				con_x[x]=t;
				con_y[t]=x;
				return true;
			}
		}
		return false;
	}

	inline int max_match(){
		memset(con_x,-1,sizeof(con_x));
		memset(con_y,-1,sizeof(con_y));
		int ret=0;
		for (int i=0;i<v1.size();i++) memset(vis,0,sizeof(vis)),ret+=DFS(v1[i]);
		return ret;
	}

	inline bool check(int x){
		for (int i=0;i<n;i++) con_x_tmp[i]=con_x[i],con_y_tmp[i]=con_y[i];
		now_block=x;
		if (a[x]==0){
			for (int i=lnk[con_x[x]];i;i=nxt[i]) if (son[i]!=x){
				memset(vis,0,sizeof(vis));
				vis[con_x[x]]=true;
				if (DFS(son[i])){
					for (int j=0;j<n;j++) con_x[j]=con_x_tmp[j],con_y[j]=con_y_tmp[j];
					return false;
				}
			}
			con_y[con_x[x]]=-1;con_x[x]=-1;
			blocked[x]=true;
			return true;
		} else {
			memset(vis,0,sizeof(vis));
			con_x[con_y[x]]=-1;
			if (DFS(con_y[x])){
				for (int i=0;i<n;i++) con_x[i]=con_x_tmp[i],con_y[i]=con_y_tmp[i];
				return false;
			}
			con_y[x]=-1;
			blocked[x]=true;
			return true;
		}
	}
};

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

signed main(){
	T=read();
	while (T--){
		Graph::init();
		n=read();m=read();
		for (int i=0;i<n;i++){
			a[i]=read();
			if (a[i]) v2.push_back(i); else v1.push_back(i);
		}
		for (int i=0;i<m;i++){
			int x=read(),y=read();
			if (a[x]==a[y]) continue;
			Graph::add_edge(x,y);
			Graph::add_edge(y,x);
		}
		int ans=Graph::max_match();
		printf("%lld ",ans);
		int cnt=0;
		for (int i=0;i<n && cnt<ans;i++) if ((a[i]==0 && Graph::con_x[i]!=-1)||(a[i]==1 && Graph::con_y[i]!=-1)) if (Graph::check(i)) printf("%lld ",i),cnt++;
		printf("\n");
	}
	return 0;
}
