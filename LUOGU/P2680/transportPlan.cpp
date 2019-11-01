#pragma GCC optimize(2)

#include<bits/stdc++.h>

#define int long long

#define pii pair<int,int>
const int INF=0x3f3f3f3f3f3f3f3f;
const int NEG_INF=0x8080808080808080;

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=300005,maxe=600005;

class segmentTree{
	#define ls (p<<1)
	#define rs (p<<1|1)
	#define mid (((tr-tl)>>1)+tl)

	private:
		int tree[maxn*4],mx[maxn*4],tag[maxn*4],tagm[maxn*4];

		void push_down(int tl,int tr,int p){
			tree[ls]+=tag[p]*(mid-tl+1); tag[ls]+=tag[p];
			tree[rs]+=tag[p]*(tr-mid); tag[rs]+=tag[p];
			// ! v!e!r!y ! i!m!p!o!r!t!a!n!t !
			mx[ls]=max(mx[ls],tagm[p]); tagm[ls]=max(tagm[ls],tagm[p]);
			mx[rs]=max(mx[rs],tagm[p]); tagm[rs]=max(tagm[rs],tagm[p]);
			tag[p]=tagm[p]=0;
		}

	public:
		segmentTree(){
			memset(tree,0,sizeof(tree));
			memset(mx,0,sizeof(mx));
			memset(tag,0,sizeof(tag));
			memset(tagm,0,sizeof(tagm));
		}

		void update(int sl,int sr,int tl,int tr,int p,int delta){
			if (sl<=tl && tr<=sr) return (void)(tree[p]+=delta*(tr-tl+1),tag[p]+=delta);
			push_down(tl,tr,p);
			if (sl<=mid  ) update(sl,sr,tl,mid,ls,delta);
			if (mid+1<=sr) update(sl,sr,mid+1,tr,rs,delta);
			tree[p]=tree[ls]+tree[rs];
		}

		void update_mx(int sl,int sr,int tl,int tr,int p,int delta){
			if (sl>sr) return;
			if (sl<=tl && tr<=sr) return (void)(mx[p]=max(mx[p],delta),tagm[p]=max(tagm[p],delta));
			push_down(tl,tr,p);
			if (sl<=mid  ) update_mx(sl,sr,tl,mid,ls,delta);
			if (mid+1<=sr) update_mx(sl,sr,mid+1,tr,rs,delta);
			mx[p]=max(mx[ls],mx[rs]);
		}

		int query(int sl,int sr,int tl,int tr,int p){
			if (sl<=tl && tr<=sr) return tree[p];
			push_down(tl,tr,p);
			int ret=0;
			if (sl<=mid  ) ret+=query(sl,sr,tl,mid,ls);
			if (mid+1<=sr) ret+=query(sl,sr,mid+1,tr,rs);
			return ret;
		}

		int query_mx(int sl,int sr,int tl,int tr,int p){
			if (sl<=tl && tr<=sr) return mx[p];
			push_down(tl,tr,p);
			int ret=0;
			if (sl<=mid  ) ret=max(ret,query_mx(sl,sr,tl,mid,ls));
			if (mid+1<=sr) ret=max(ret,query_mx(sl,sr,mid+1,tr,rs));
			return ret;
		}

	#undef ls
	#undef rs
	#undef mid
};

int n,m,ans=INF;

int tot=0,lnk[maxn],nxt[maxe],to[maxe],w[maxe];
bool vis[maxn];

pii q[maxn];
bool compare_pii_first(pii aa,pii bb){return aa.first < bb.first;}
int max_path=-1,max_a,max_b;

void add_edge(int x,int y,int z){
	tot++;to[tot]=y;w[tot]=z;
	nxt[tot]=lnk[x];lnk[x]=tot;
}

namespace HLD{ // Heavy-light decomposition
	segmentTree t;

	int size[maxn],son[maxn],fa[maxn],deep[maxn];
	int top[maxn],id[maxn],cnt=0;
	int v[maxn];

	void build_tree(int x){
		size[x]=1,son[x]=-1;
		int maxson=0;
		for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=fa[x]){
			deep[to[i]]=deep[x]+1; fa[to[i]]=x; v[to[i]]=w[i];
			build_tree(to[i]);
			size[x]+=size[to[i]];
			if (size[to[i]]>maxson) maxson=size[to[i]],son[x]=to[i];
		}
	}

	void build_chain(int x){
		id[x]=++cnt;
		if (son[fa[x]]==x) top[x]=top[fa[x]]; else top[x]=x;
		if (son[x]!=-1) build_chain(son[x]);
		for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=fa[x] && to[i]!=son[x]) build_chain(to[i]);
	}

	void update_chain(int x,int y,int delta){
		while (top[x]!=top[y]){
			if (deep[top[x]]<deep[top[y]]) swap(x,y);
			t.update(id[top[x]],id[x],1,n,1,delta);
			x=fa[top[x]];
		}
		if (id[x]<id[y]) swap(x,y);
		t.update(id[y],id[x],1,n,1,delta);
	}

	int query_sum_chain(int x,int y){
		int ret=0;
		while (top[x]!=top[y]){
			if (deep[top[x]]<deep[top[y]]) swap(x,y);
			ret+=t.query(id[top[x]],id[x],1,n,1);
			x=fa[top[x]];
		}
		if (id[x]<id[y]) swap(x,y);
		ret+=t.query(id[y]+1,id[x],1,n,1);
		return ret;
	}

	void update_subtree(int x,int delta){
		t.update(id[x],id[x]+size[x]-1,1,n,1,delta);
	}

	int query_subtree(int x){
		return t.query(id[x],id[x]+size[x]-1,1,n,1);
	}

	void build_mx(int x,int y){
		int nowlen=query_sum_chain(x,y);
		if (nowlen>max_path) max_path=nowlen,max_a=x,max_b=y;
		vector<pii> vec; vec.clear();
		while (top[x]!=top[y]){
			if (deep[top[x]]<deep[top[y]]) swap(x,y);
			vec.push_back(make_pair(id[top[x]],id[x]));
			x=fa[top[x]];
		}
		if (id[x]<id[y]) swap(x,y);
		vec.push_back(make_pair(id[y]+1,id[x])); // To be checked

		sort(vec.begin(),vec.end(),compare_pii_first);
		t.update_mx(1,vec[0].first-1,1,n,1,nowlen);
		for (int i=0;i<(int)vec.size()-1;i++) t.update_mx(vec[i].second+1,vec[i+1].first-1,1,n,1,nowlen);
		t.update_mx(vec[(int)vec.size()-1].second+1,n,1,n,1,nowlen);
	}

	void init_value(){
		for (int i=1;i<=n;i++) t.update(id[i],id[i],1,n,1,v[i]);
	}

	void make_flag(int x,int y){
		if (deep[x]<deep[y]) swap(x,y);
		while (deep[x]>deep[y]) vis[x]=true,x=fa[x];
		while (x!=y) vis[x]=vis[y]=true,x=fa[x],y=fa[y];
	}
}

signed main(){
	#ifdef DEBUG
		freopen("testdata.in","r",stdin);
	#endif

	n=read(),m=read();
	for (int i=1;i<n;i++){
		int x=read(),y=read(),z=read();
		add_edge(x,y,z);add_edge(y,x,z);
	}

	HLD::deep[1]=1;
	HLD::build_tree(1);
	HLD::build_chain(1);
	HLD::init_value();

	for (int i=1;i<=m;i++) q[i].first=read(),q[i].second=read(),HLD::build_mx(q[i].first,q[i].second);

	HLD::make_flag(max_a,max_b);

	ans=max_path;
	for (int i=2;i<=n;i++)
		if (vis[i]) ans=min(ans,max(max_path-HLD::v[i], HLD::t.query_mx(HLD::id[i],HLD::id[i],1,n,1)));

	printf("%lld\n",ans);
	return 0;
}