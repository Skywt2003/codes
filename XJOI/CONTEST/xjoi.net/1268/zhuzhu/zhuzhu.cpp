#include<bits/stdc++.h>
using namespace std;

#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}


const int tt=1e9+7;
const int INF=0x3f3f3f3f3f3f3f3f;

const int maxn=1e5+5,maxe=4e5+5;

int T;
int n,m,X;
int ans=0;
int tot=0,lnk[maxn],nxt[maxe],to[maxe],w[maxe];
int f[maxn][25],mx[maxn][25],deep[maxn];

struct edge{
	int x,y,w;
	bool inc;
};
edge a[maxe];

int qsm(int a,int b){
	int ret=1,w=a%tt;
	while (b){
		if (b&1) ret=ret*w%tt;
		w=w*w%tt; b>>=1;
	}
	return ret;
}

class uniSet{
	private:
		int fa[maxn];
	
	public:
		void init(int n){
			for (int i=0;i<=n;i++) fa[i]=i;
		}

		int getfa(int x){
			return (fa[x]==x)?x:fa[x]=getfa(fa[x]);
		}

		void merge(int x,int y){
			x=getfa(x),y=getfa(y);
			if (x!=y) fa[x]=y;
		}
};

uniSet u;

void clear_graph(){
	tot=0;
	memset(lnk,0,sizeof(lnk));
	memset(nxt,0,sizeof(nxt));
	memset(to,0,sizeof(to));
	memset(w,0,sizeof(w));
	
	memset(f,0,sizeof(f));
	memset(mx,0,sizeof(mx));
	memset(deep,0,sizeof(deep));
}

void add_edge(int x,int y,int z){
	tot++; to[tot]=y; w[tot]=z;
	nxt[tot]=lnk[x]; lnk[x]=tot;
}

void build_tree(int x){
	for (int j=1;j<25;j++)
		f[x][j]=f[f[x][j-1]][j-1],mx[x][j]=max(mx[x][j-1],mx[f[x][j-1]][j-1]);
	for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=f[x][0]){
		deep[to[i]]=deep[x]+1;
		f[to[i]][0]=x; mx[to[i]][0]=w[i];
		build_tree(to[i]);
	}
}

int get_lca_weight(int x,int y){
	int ans=0;
	if (deep[x]<deep[y]) swap(x,y);
	for (int i=24;i>=0;i--) if (deep[f[x][i]] >= deep[y]) ans=max(ans,mx[x][i]),x=f[x][i];
	if (x==y) return ans;
	for (int i=24;i>=0;i--) if (f[x][i]!=f[y][i]) ans=max(ans,max(mx[x][i],mx[y][i])),x=f[x][i],y=f[y][i];
	return max(ans,max(mx[x][0],mx[y][0]));
}

bool compare_w(edge aa,edge bb){
	return aa.w < bb.w;
}

int Kruskal(){
	sort(a+1,a+1+m,compare_w);
	int sum=0;
	u.init(n);
	for (int i=1;i<=m;i++){
		int x=u.getfa(a[i].x),y=u.getfa(a[i].y);
		if (x==y) continue;
		add_edge(a[i].x,a[i].y,a[i].w), add_edge(a[i].y,a[i].x,a[i].w);
		a[i].inc=true; sum+=a[i].w;
		u.merge(x,y);
	}
	return sum;
}

signed main(){
	T=read();
	while (T--){
		n=read(); m=read(); X=read();
		for (int i=1;i<=m;i++) a[i].x=read(),a[i].y=read(),a[i].w=read(),a[i].inc=false;
		clear_graph();

		int sum=Kruskal();
		deep[1]=1;
		build_tree(1);

		int cnt=0;
		int prob=0,ban=0;
		for (int i=1;i<=m;i++) if (!a[i].inc){
			int route_max = get_lca_weight(a[i].x,a[i].y);
			if (sum-route_max+a[i].w == X) prob++; else
			if (sum-route_max+a[i].w < X) ban++; else
			cnt++;
		}

		// printf("%lld\n",cnt);
		// prob++;
		if (sum==X) ans=(qsm(2,m) - 2*qsm(2,cnt)%tt + tt)%tt;
		else if (sum<X) ans=(2*qsm(2,m-(n-1)-ban)%tt-2*qsm(2,m-(n-1)-ban-prob)%tt+tt)%tt;
		else ans=0;

		printf("%lld\n",ans);
	}
	return 0;
}