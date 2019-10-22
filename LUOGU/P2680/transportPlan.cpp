#include<bits/stdc++.h>
#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=300005,maxe=600005;

class segmentTree{
	#define ls ((p<<1))
	#define rs ((p<<1)+1)
	#define mid (((tr-tl)>>1)+tl)

	private:
		int tree[maxn*4],tag[maxn*4],mx[maxn*4];

		void push_down(int tl,int tr,int p){
			tree[ls]+=tag[p]*(mid-tl+1);
			tree[rs]+=tag[p]*(tr-mid);
			tag[ls]+=tag[p],tag[rs]+=tag[p];
			mx[ls]=mx[rs]=mx[p];
			tag[p]=0;
		}

	public:
		segmentTree(){
			memset(tree,0,sizeof(tree));
			memset(tag,0,sizeof(tag));
			memset(mx,0,sizeof(mx));
		}

		void update(int sl,int sr,int tl,int tr,int p,int delta){
			if (sl<=tl && tr<=sr) return (void)(tree[p]+=delta*(tr-tl+1),tag[p]+=delta); // IMP
			push_down(tl,tr,p);
			if (sl<=mid  ) update(sl,sr,tl,mid,ls,delta);
			if (mid+1<=sr) update(sl,sr,mid+1,tr,rs,delta);
			tree[p]=tree[ls]+tree[rs];
		}

		void update_mx(int sl,int sr,int tl,int tr,int p,int delta){
			if (sl<=tl && tr<=sr) return (void)(mx[p]=max(mx[p],delta)); // IMP
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
		int query(int x,int tl,int tr,int p){
			if (tl==tr && tl==x) return tree[p];
			push_down(tl,tr,p);
			int ret=0;
			if (x<=mid  ) ret+=query(x,tl,mid,ls);
			if (mid+1<=x) ret+=query(x,mid+1,tr,rs);
			return ret;
		}

		int query_mx(int sl,int sr,int tl,int tr,int p){
			if (sl<=tl && tr<=sr) return mx[p];
			push_down(tl,tr,p);
			int ret=0;
			if (sl<=mid  ) ret=max(ret,query(sl,sr,tl,mid,ls));
			if (mid+1<=sr) ret=max(ret,query(sl,sr,mid+1,tr,rs));
			return ret;
		}

	#undef ls
	#undef rs
	#undef mid
};

int n,m,ans=0;

int tot=0,lnk[maxn],nxt[maxe],to[maxe],w[maxe];
int size[maxn],son[maxn],fa[maxn],deep[maxn];
int top[maxn],id[maxn],cnt=0;
int v[maxn];

segmentTree t;

pair<int,int> q[maxn];
bool compare_pii_first(pair<int,int> aa,pair<int,int> bb){return aa.first < bb.first;}

bool vis[maxn];


void add_edge(int x,int y,int z){
	tot++;to[tot]=y;w[tot]=z;
	nxt[tot]=lnk[x];lnk[x]=tot;
}

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
	ret+=t.query(id[y],id[x],1,n,1);
	return ret;
}

void update_subtree(int x,int delta){
	t.update(id[x],id[x]+size[x]-1,1,n,1,delta);
}

int query_subtree(int x){
	return t.query(id[x],id[x]+size[x]-1,1,n,1);
}



void build_mx(int x,int y,int k){
	int nowlen=0;
	vector<pair<int,int> > vec; vec.clear();
	while (top[x]!=top[y]){
		if (deep[top[x]]<deep[top[y]]) swap(x,y);
		vec.push_back(make_pair(id[top[x]],id[x])); nowlen+=id[x]-id[top[x]]+1;
		x=fa[top[x]];
	}
	if (id[x]<id[y]) swap(x,y);
	vec.push_back(make_pair(id[y],id[x])); nowlen+=id[y]-id[x]+1;

	sort(vec.begin(),vec.end(),compare_pii_first);
	t.update_mx(1,vec[0].first-1,1,n,1,nowlen);
	for (int i=1;i<vec.size()-1;i++) t.update_mx(vec[i].second+1,vec[i+1].first-1,1,n,1,nowlen);
	t.update(vec[vec.size()-1].first+1,n,1,n,1,nowlen);
}


pair<int,int> get_dist(int x,int from){
	pair<int,int> ret=make_pair(x,0);
	for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=from){
		pair<int,int> now=get_dist(to[i],x);
		if (now.second+w[i] > ret.second) ret=now;
	}
	return ret;
}

bool flg=false;
void set_vertex(int s,int t,int from){
	if (flg) return;
	if (s==t) return (void)(flg=true);
	vis[s]=true;
	for (int i=lnk[s];i;i=nxt[i]) if (to[i]!=from) set_vertex(to[i],t,s);
	vis[s]=false;
}

signed main(){
	#ifndef ONLINE_JUDGE
		freopen("data.in","r",stdin);
	#endif

	n=read(),m=read();
	for (int i=1;i<n;i++){
		int x=read(),y=read(),z=read();
		add_edge(x,y,z);add_edge(y,x,z);
	}

	deep[1]=1;
	build_tree(1);
	build_chain(1);

	#ifdef EBUG
		printf("Finish building the treecut\n");
	#endif

	for (int i=1;i<=n;i++) t.update(id[i],id[i],1,n,1,v[i]);

	for (int i=1;i<=m;i++){
		q[i].first=read(),q[i].second=read();
		build_mx(q[i].first,q[i].second,i);
	}

	#ifdef EBUG
		printf("FInish building MX\n");
	#endif

	int da,db,dc;
	da=get_dist(1,-1).first;
	pair<int,int> tmp=get_dist(da,-1);
	db=tmp.first; dc=tmp.second;
	set_vertex(da,db,-1);

	for (int i=1;i<=n;i++) if (vis[i]) ans=min(ans,max(dc-v[i],t.query_mx(i,i,1,n,1)));

	printf("%lld\n",ans);

	return 0;
}