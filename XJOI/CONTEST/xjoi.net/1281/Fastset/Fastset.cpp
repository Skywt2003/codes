#pragma GCC target("avx")
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")

#include<bits/stdc++.h>

// #define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=3e5+5;

int get_dist(int x,int y);

inline int max(int x,int y){
	return (x>y)?x:y;
}
inline int min(int x,int y){
	return (x<y)?x:y;
}

#define ls (p<<1)
#define rs (p<<1|1)
class segmentTree{
	private:
		struct node{
			int val,l,r;
		};
		node tree[maxn*4];

		void push_down(int p){
			if (!tree[p].val) return;
			tree[ls].val=tree[rs].val=tree[p].val;
		}

	public:
		void build(int tl,int tr,int p){
			tree[p].l=tl;tree[p].r=tr;
			if (tl==tr) {tree[p].val=tl;return;}
			int mid=((tr-tl)>>1)+tl;
			build(tl,mid,ls); build(mid+1,tr,rs);
		}

		void update(int sl,int sr,int p,int delta){
			if (sl<=tree[p].l && tree[p].r<=sr){
				tree[p].val=delta;
				return;
			}
			push_down(p);
			int mid=((tree[p].r-tree[p].l)>>1)+tree[p].l;
			if (sl<=mid  ) update(sl,sr,ls,delta);
			if (mid+1<=sr) update(sl,sr,rs,delta);
			tree[p].val=((tree[ls].val==tree[rs].val)?tree[ls].val:0);
		}

		long long query(int sl,int sr,int p,int x){
			if (tree[p].val) return 1ll*get_dist(x,tree[p].val)*(min(tree[p].r,sr)-max(tree[p].l,sl)+1);
			push_down(p);
			long long ret=0;
			int mid=((tree[p].r-tree[p].l)>>1)+tree[p].l;
			if (sl<=mid  ) ret+=query(sl,sr,ls,x);
			if (mid+1<=sr) ret+=query(sl,sr,rs,x);
			return ret;
		}
};
#undef ls
#undef rs

int n;
int tot=0,lnk[maxn],nxt[maxn*2],to[maxn*2];
int f[maxn][22],deep[maxn];

segmentTree t;

void add_edge(int x,int y){
	tot++; to[tot]=y;
	nxt[tot]=lnk[x]; lnk[x]=tot;
}

void build_tree(int x){
	for (int j=1;j<21;j++)
		f[x][j]=f[f[x][j-1]][j-1];
	for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=f[x][0]){
		f[to[i]][0]=x; deep[to[i]]=deep[x]+1;
		build_tree(to[i]);
	}
}

int get_lca(int x,int y){
	if (deep[x]<deep[y]) swap(x,y);
	for (int i=20;i>=0;i--) if (deep[f[x][i]] >= deep[y]) x=f[x][i];
	if (x==y) return x;
	for (int i=20;i>=0;i--) if (f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}

int get_dist(int x,int y){
	int l=get_lca(x,y);
	return deep[x]-deep[l]+deep[y]-deep[l];
}

long long ans=0;

signed main(){
	n=read();
	for (int i=1;i<n;i++){
		int x=read(),y=read();
		add_edge(x,y); add_edge(y,x);
	}

	deep[1]=1;
	build_tree(1);
	
	t.build(1,n,1);
	for (int i=1;i<=n;i++){
		int l=read(),r=read(),p=read();
		ans+=t.query(l,r,1,p);
		t.update(l,r,1,p);
	}
	printf("%lld\n",ans);
	return 0;
}