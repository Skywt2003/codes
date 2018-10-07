#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
using namespace std;

#define clear(_) memset(_,0,sizeof(_))
#define write(_) cout<<#_<<" = "<<_<<endl;

const int maxn=200005;

int n,m,k,q;
int a[maxn],b[maxn];
bool vis[maxn];

struct Query{
	int v,n,id;
	vector <int> broken;
};
vector <Query> queries;

struct Edge{
	int x,y,w;
};
vector <Edge> e;

struct Answer{
	int id,x;
};
vector <Answer> ans;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

inline bool compare(Query aa,Query bb){
	return aa.v<bb.v;
}

inline bool compare_edges(Edge aa,Edge bb){
	return aa.w<bb.w;
}

inline bool compare_id(Answer aa,Answer bb){
	return aa.id<bb.id;
}

namespace UnionFind{
	int fa[maxn],sum[maxn],cnt[maxn];
	multiset <int> st[maxn];
	multiset <int>::iterator it;

	inline void init(){
		for (int i=1;i<=n;i++) fa[i]=i,sum[i]=1,st[i].insert(b[i]);
		st.clear();
	}
	inline int getfa(int x){
		if (fa[x]==x) return x;
		fa[x]=getfa(fa[x]);
		return fa[x];
	}
	inline void merge(int x,int y){
		int fx=getfa(x),fy=getfa(y);
		if (fx==fy) return;
		if (sum[fx]<sum[fy]) swap(fx,fy);
		fa[fy]=fx;
		sum[fx]+=sum[fy];sum[fy]=0;
		for (it=st[fy].begin();it!=st[fy].end();it++) st[fx].insert(*it);
		cnt[fx]=cnt[fy]=0;
		int lastnum=-1;
		for (it=st[fy].begin();it!=st[fy].end();it++) if (*it!=lastnum){
			lastnum=*it;
			int now=st[fx].count(*it);
			if (now%k==0) cnt[fx]++;
		}
	}
}

int main(){
	n=read();m=read();k=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) b[i]=read();
	for (int i=1;i<=m;i++){
		int x=read(),y=read();
		e.push_back((Edge){x,y,max(a[x],a[y])});
	}
	q=read():
	for (int i=1;i<=q;i++){
		int vv=read(),nn=read(),id=i;
		vector <int> now;now.clear();
		for (int j=1;j<=nn;j++) now.push_back(read());
		queries.push_back((Query){vv,nn,id,now});
	}
	sort(e.begin(),e.end(),compare_edges);
	sort(queries.begin(),queries.end(),compare);
	int lst=-1;
	UnionFind::init();
	for (int i=1;i<=q;i++){
		clear(vis);
		while (e[lst+1].w<=queries[i].v){
			lst++;
			UnionFind::merge(e[lst].x,e[lst].y);
		}
		for (int j=0;j<queries[i].broken.size();j++) vis[queries[i].broken[j]]=false;
		int now_ans=0;
		for (int j=1;j<=n;j++) if (fa[j]==j) now_ans=max(now_ans,cnt[j]);
		ans.push_back((Answer){queries[i].id,now_ans});
	}
	sort(ans.begin(),ans.end(),compare_id);
	for (int i=0;i<ans.size();i++) printf("%d\n",ans[i].x);
	return 0;
}