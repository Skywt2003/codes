#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

#define int long long
using namespace std;

const int maxn=2e5+5;

int n,q;

namespace BIT{
	int tree[maxn];

	inline void init(){
		memset(tree,0,sizeof(tree));
	}

	inline int lowbit(int x){
		return x&(-x);
	}

	inline void update(int x,int delta){
		while (x<=n) tree[x]+=delta,x+=lowbit(x);
	}

	inline int query(int x){
		int ret=0;
		while (x) ret+=tree[x],x-=lowbit(x);
		return ret;
	}

	inline int query(int x,int y){
		return query(y)-query(x-1);
	}
}

namespace Graph{
	int value[maxn];
	int tot=0,lnk[maxn],nxt[maxn*2],son[maxn*2];
	int fa[maxn];
	pair<int,int> seg[maxn];
	int order[maxn],cnt=0;

	inline void init(){
		tot=0;cnt=0;
		memset(value,0,sizeof(value));
		memset(order,0,sizeof(order));
		memset(lnk,0,sizeof(lnk));
		memset(nxt,0,sizeof(nxt));
		memset(son,0,sizeof(son));
		memset(seg,0,sizeof(seg));
		memset(fa,0,sizeof(fa));
	}

	inline void add_edge(int x,int y){
		tot++;son[tot]=y;
		nxt[tot]=lnk[x];lnk[x]=tot;
	}

	inline void build_tree(int x){
		order[++cnt]=x;
		seg[x].first=cnt;
		for (int i=lnk[x];i;i=nxt[i]) if (son[i]!=fa[x]){
			fa[son[i]]=x;
			build_tree(son[i]);
		}
		seg[x].second=cnt;
	}
}

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

inline char read_char(){
	char ch=getchar();
	while (ch!='C' && ch!='Q') ch=getchar();
	return ch;
}

signed main(){
	Graph::init();BIT::init();
	n=read();
	for (int i=1;i<=n;i++) Graph::value[i]=1,BIT::update(i,1);
	for (int i=1;i<n;i++){
		int x=read(),y=read();
		Graph::add_edge(x,y);
		Graph::add_edge(y,x);
	}
	Graph::build_tree(1);
	q=read();
	for (int i=1;i<=q;i++){
		char opt=read_char();
		if (opt=='C'){
			int x=read();
			if (Graph::value[x]) BIT::update(Graph::seg[x].first,-1); else BIT::update(Graph::seg[x].first, 1);
			Graph::value[x]=1-Graph::value[x];
		} else if (opt=='Q'){
			int x=read();
			printf("%lld\n",BIT::query(Graph::seg[x].first,Graph::seg[x].second));
		}
	}
	return 0;
}