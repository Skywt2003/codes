#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

#define int long long
using namespace std;

const int maxn=1e5+5,maxe=2e5+5;
int n,m,q;
int tot=0,lnk[maxn],nxt[maxe],son[maxe];
vector<pair<int,int> > vec;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

inline void add_edge(int x,int y){
	tot++;son[tot]=y;
	nxt[tot]=lnk[x];lnk[x]=tot;
}

namespace UniSet{
	int fa[maxn];

	inline void init(int n){
		for (int i=1;i<=n;i++) fa[i]=i;
	}

	inline int getfa(int x){
		if (fa[x]==x) return x;
		fa[x]=getfa(fa[x]);
		return fa[x];
	}

	inline void merge(int x,int y){
		x=getfa(x),y=getfa(y);
		if (x!=y) fa[x]=y;
	}
}

inline void solve(){
	for (int i=1;i<=n;i++){
		UniSet::init(n);
		for (int j=i;j<=n;j++){
			bool flg=true;
			for (int k=lnk[j];k;k=nxt[k]) if (son[k]>=i && son[k]<=j){
				int x=UniSet::getfa(j),y=UniSet::getfa(son[k]);
				if (x==y) {flg=false;break;} else UniSet::fa[x]=y;
			}
			if (!flg) break;
			vec.push_back(make_pair(i,j));
		}
	}
}

inline int query(int x,int y){
	int ret=0;
	for (int i=0;i<vec.size();i++) ret+=(vec[i].first>=x && vec[i].second<=y);
	return ret;
}

signed main(){
	n=read();m=read();
	for (int i=1;i<=m;i++){
		int x=read(),y=read();
		add_edge(x,y);add_edge(y,x);
	}
	solve();
	q=read();
	for (int i=1;i<=q;i++){
		int x=read(),y=read();
		printf("%lld\n",query(x,y));
	}
	return 0;
}