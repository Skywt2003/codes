#include<bits/stdc++.h>
using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1e5+5,maxe=2e5+5;
const int NZ=1e5;
int n,m;

#define ls ((p<<1))
#define rs ((p<<1)+1)
#define mid (((tr-tl)>>1)+tl)

class valueSegmentTree{

	private:
		int tree[maxn*4],rst[maxn*4];

	public:
		void init(int tl,int tr,int p){
			if (tl>tr) return;
			if (tl==tr) {rst[p]=tl;return;}
			init(tl,mid,ls); init(mid+1,tr,rs);
		}

		void update(int x,int tl,int tr,int p,int delta){
			if (tl==tr && tl==x){tree[p]+=delta;return;}
			if (x<=mid  ) update(x,tl,mid,ls,delta);
			if (mid+1<=x) update(x,mid+1,tr,rs,delta);
			tree[p]=max(tree[ls],tree[rs]);
			if (tree[ls]>=tree[rs]) rst[p]=rst[ls]; else rst[p]=rst[rs];
		}

		int query(){
			if (tree[1]==0) return 0;
			return rst[1];
		}
};

int tot=0,lnk[maxn],nxt[maxe],to[maxe];
int size[maxn],son[maxn],fa[maxn],deep[maxn];
int top[maxn],id[maxn],pre[maxn],cnt=0;
int f[maxn][25];
vector<pair<int,int> > vec[maxn];

valueSegmentTree t;
int ans[maxn];

void addEdge(int x,int y){
	tot++;to[tot]=y;
	nxt[tot]=lnk[x];lnk[x]=tot;
}

void buildTree(int x){
	size[x]=1,son[x]=-1;
	int maxson=0;
	for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=fa[x]){
		deep[to[i]]=deep[x]+1;fa[to[i]]=x;
		buildTree(to[i]);
		size[x]+=size[to[i]];
		if (size[to[i]]>maxson) maxson=size[to[i]],son[x]=to[i];
	}
}

void buildChain(int x){
	f[x][0]=fa[x]; for (int j=1;j<=23;j++) f[x][j]=f[f[x][j-1]][j-1];
	id[x]=++cnt;pre[id[x]]=x;
	if (son[fa[x]]==x) top[x]=top[fa[x]]; else top[x]=x;
	if (son[x]!=-1) buildChain(son[x]);
	for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=fa[x] && to[i]!=son[x]) buildChain(to[i]);
}

int getLCA(int x,int y){
	if (deep[x]>deep[y]) swap(x,y);
	for (int i=23;i>=0;i--) if (deep[f[y][i]]>=deep[x]) y=f[y][i];
	if (x==y) return x;
	for (int i=23;i>=0;i--) if (f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return fa[x];
}

void addSegment(int s,int t,int z){
	vec[s].push_back(make_pair(z,1));
	vec[t+1].push_back(make_pair(z,-1));
}

void updateChain(int x,int y,int delta){
	int ff=getLCA(x,y);
	addSegment(id[ff],id[ff],delta);
	for (int tmp=1;tmp<=2;tmp++){
		while (x!=ff){
			if (top[x]!=x){
				if (deep[top[x]]>=deep[ff]) addSegment(id[top[x]]+1,id[x],delta),x=top[x];
				else addSegment(id[ff]+1,id[x],delta),x=ff;
			} else addSegment(id[x],id[x],delta),x=fa[x];
		}
		x=y;
	}
}

void getAnswer(){
	t.init(1,NZ,1);
	for (int i=1;i<=n;i++){
		for (int j=0;j<vec[i].size();j++){
			pair<int,int> now=vec[i][j];
			t.update(now.first,1,NZ,1,now.second);
		}
		ans[pre[i]]=t.query();
	}
}

signed main(){
	n=read();m=read();
	for (int i=1;i<n;i++){
		int x=read(),y=read();
		addEdge(x,y);addEdge(y,x);
	}

	deep[1]=1;
	buildTree(1);
	buildChain(1);

	while (m--){
		int x=read(),y=read(),z=read();
		updateChain(x,y,z);
	}

	getAnswer();

	for (int i=1;i<=n;i++) printf("%d\n",ans[i]);

	return 0;
}