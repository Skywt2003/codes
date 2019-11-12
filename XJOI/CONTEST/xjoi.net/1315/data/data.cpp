// 数据有点水……
// 我这个暴力做法，如果树是链的话应该可以卡到 N^2 的……

// #pragma GCC optimize(2)

#include<bits/stdc++.h>

// #define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=100005,maxe=200005;

int n,q;

int tot=0,lnk[maxn],nxt[maxe],to[maxe];
int fa[maxn];

struct query{int x,k,id,ans;};
vector<query> vec[maxn];
vector<query> queries;
bool compare_query_k(query aa,query bb){return aa.k < bb.k;}
bool compare_query_id(query aa,query bb){return aa.id < bb.id;}

struct node{int x,val;};
vector<node> nodes;
bool compare_node_val(node aa,node bb){return aa.val < bb.val;}

int ptr[maxn],cnt[maxn];

void add_edge(int x,int y){
	tot++; to[tot]=y;
	nxt[tot]=lnk[x]; lnk[x]=tot;
}

void build_tree(int x){
	for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=fa[x]) fa[to[i]]=x,build_tree(to[i]);
}

signed main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);

	n=read();
	for (int i=1;i<=n;i++){
		int x=read();
		nodes.push_back((node){i,x});
	}
	
	for (int i=1;i<n;i++){
		int x=read(),y=read();
		add_edge(x,y);add_edge(y,x);
	}
	
	build_tree(1);
	
	q=read();
	for (int i=1;i<=q;i++){
		int x=read(),y=read();
		queries.push_back((query){x,y,i,-1});
	}
	sort(queries.begin(),queries.end(),compare_query_k);
	for (int i=0;i<queries.size();i++) vec[queries[i].x].push_back(queries[i]);
	
	sort(nodes.begin(),nodes.end(),compare_node_val);
	for (int i=0;i<n;i++){
		int x=nodes[i].x;
		while (x){
			cnt[x]++;
			while (ptr[x]<vec[x].size() && cnt[x]==vec[x][ptr[x]].k) vec[x][ptr[x]].ans=nodes[i].val,ptr[x]++;
			x=fa[x];
		}
	}
	
	queries.clear();
	for (int i=1;i<=n;i++)
		for (int j=0;j<vec[i].size();j++)
			queries.push_back(vec[i][j]);
	sort(queries.begin(),queries.end(),compare_query_id);
	for (int i=0;i<queries.size();i++) printf("%lld\n",queries[i].ans);
	
	return 0;
}
