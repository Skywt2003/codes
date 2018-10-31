#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>

#define int long long
using namespace std;

const int maxn=4005,maxe=2000005;
int n,m,e;

vector<pair<int,int> > vec_ans;
// vector<pair<int,int> > tmp;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

namespace Graph{
	int tot=0,lnk[maxn],son[maxe],nxt[maxe];
	bool vis[maxn];
	int con_x[maxn],con_y[maxn];

	inline void add_edge(int x,int y){
		tot++;son[tot]=y;
		nxt[tot]=lnk[x];lnk[x]=tot;
	}

	inline void init(){
		tot=0;
		memset(lnk,0,sizeof(lnk));
		memset(son,0,sizeof(son));
		memset(nxt,0,sizeof(nxt));
		vec_ans.clear();
		// tmp.clear();
	}

	inline bool DFS(int s){
		for (int i=lnk[s];i;i=nxt[i]) if (!vis[son[i]]){
			int t=son[i];vis[t]=true;
			if ((con_y[t]==-1)||(DFS(con_y[t]))){
				con_x[s]=t;
				con_y[t]=s;
				return true;
			}
		}
		return false;
	}

	inline int max_match(){
		memset(con_x,-1,sizeof(con_x));
		memset(con_y,-1,sizeof(con_y));
		int ret=0;
		for (int i=1;i<=n;i++){
			memset(vis,0,sizeof(vis));
			ret+=DFS(i);
		}
		return ret;
	}

	inline void DFS_Path(int x){
		vis[x]=true;
		for (int i=lnk[x];i;i=nxt[i]) if (con_x[son[i]]!=-1 && vis[son[i]]==false && vis[con_x[son[i]]]==false){
			vis[son[i]]=true;
			DFS_Path(con_x[son[i]]);
		}
	}

	inline void make_answer(){
		memset(vis,0,sizeof(vis));
		for (int i=n+1;i<=n+m;i++) if ((!vis[i]) && con_y[i]==-1) DFS_Path(i);
		for (int i=1;i<=n;i++) if (vis[i]) vec_ans.push_back(make_pair(0,i));
		for (int i=n+1;i<=n+m;i++) if (!vis[i]) vec_ans.push_back(make_pair(1,i-n));
	}
}

// inline void check(){
// 	bool vis[maxn];
// 	memset(vis,0,sizeof(vis));
// 	for (int i=0;i<vec_ans.size();i++) vis[vec_ans[i].second+((vec_ans[i].first)*n)]=true;
// 	for (int i=0;i<tmp.size();i++){
// 		if ((!vis[tmp[i].first])&&(!vis[tmp[i].second])){
// 			printf("ERROR! X=%lld Y=%lld\n",tmp[i].first,tmp[i].second);
// 		}
// 	}
// }

// inline bool cmp(pair<int,int> aa,pair<int,int> bb){
// 	return (aa.first<bb.first || (aa.first==bb.first && aa.second<bb.second));
// }

signed main(){
	for (;;){
		n=read();m=read();e=read();
		if (n==0&&m==0&&e==0) break;
		Graph::init();
		for (int i=0;i<e;i++){
			int x=read(),y=read();
			Graph::add_edge(x,n+y);Graph::add_edge(n+y,x);
			// tmp.push_back(make_pair(x,n+y));
		}
		// sort(tmp.begin(),tmp.end(),cmp);
		// for (int i=0;i<tmp.size();i++) Graph::add_edge(tmp[i].first,tmp[i].second),Graph::add_edge(tmp[i].second,tmp[i].first);
		int ans=Graph::max_match();
		printf("%lld ",ans);
		Graph::make_answer();
		for (int i=0;i<vec_ans.size()-1;i++){
			putchar((vec_ans[i].first==0)?('r'):('c'));
			printf("%lld ",vec_ans[i].second);
		}
		putchar((vec_ans[vec_ans.size()-1].first==0)?('r'):('c'));
		printf("%lld\n",vec_ans[vec_ans.size()-1].second);
		// check();
	}
	return 0;
}