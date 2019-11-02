#include<bits/stdc++.h>

#define int long long

using namespace std;

const int INF=0x3f3f3f3f3f3f3f3f;
const int NEG_INF=0x8080808080808080;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=2005,maxe=4005;

int n,m,allw=0;
int a[maxn],b[maxn];
int ans=INF;

int tot=0,lnk[maxn],nxt[maxe],to[maxe],w[maxe];
struct edge{
	int x,y,w;
};
edge e[maxe];

void add_edge(int x,int y,int z){
	tot++; to[tot]=y; w[tot]=z;
	nxt[tot]=lnk[x]; lnk[x]=tot;
}

class uniset{
	private:
		int fa[maxn];
	
	public:
		int num[maxn];

		void init(int n){
			for (int i=1;i<=n;i++) fa[i]=i;
			memset(num,0,sizeof(num));
		}

		int getfa(int x){
			return (fa[x]==x)?x:fa[x]=getfa(fa[x]);
		}

		void merge(int x,int y){
			x=getfa(x),y=getfa(y);
			if (x==y) return;
			fa[x]=y; num[y]+=num[x]; num[x]=0;
		}
};
uniset u;

bool check(int x,int s,int t){
	u.init(n);
	for (int i=1;i<=m;i++) if (e[i].w<=x) u.merge(e[i].x,e[i].y);
	return u.getfa(s)==u.getfa(t);
}

#define mid (((R-L)>>1)+L)
int get_dist(int x,int y){
	int L=0,R=allw;
	int ret=-1;
	while (L<=R)
		if (check(mid,x,y)) ret=mid,R=mid-1; else L=mid+1;
	#ifdef DEBUG
		printf("Get dist (%lld,%lld) = %lld\n",x,y,ret);
	#endif
	return ret;
}
#undef mid

uniset uu;
int p[maxn];
bool used[maxn];

int get_answer(){
	#ifdef DEBUG
		printf("Checking: ");
		for (int i=1;i<=n;i++) printf("%lld ",p[i]); printf("\n");
	#endif
	int ret=0; uu.init(n);
	for (int i=1;i<=n;i++){
		if (uu.num[uu.getfa(p[i])]>=a[p[i]]) continue;
		int now=a[p[i]]*b[p[i]],nownum=a[p[i]];
		for (int j=1;j<=n;j++) if (p[i]!=j){
			int ext=uu.num[uu.getfa(j)];
			int ned=max(get_dist(p[i],j),a[p[i]]);
			if ((ned-ext)*b[j] < now) now=(ned-ext)*b[j],nownum=ned-ext;
		}
		ret+=now;
		uu.num[uu.getfa(p[i])]+=nownum;
		for (int j=1;j<=n;j++) if (get_dist(p[i],j) <= uu.num[uu.getfa(p[i])]) uu.merge(p[i],j);
		#ifdef DEBUG
			printf("Processing %lld: %lld\n",p[i],now);
		#endif
	}
	return ret;
}

void DFS(int step){
	if (step==n){
		ans=min(ans,get_answer());
		return;
	}
	for (int i=1;i<=n;i++) if (!used[i]){
		used[i]=true,p[step+1]=i;
		DFS(step+1);
		used[i]=false;
	}
}

signed main(){
	#ifdef DEBUG
		freopen("data.in","r",stdin);
	#endif
	n=read(); m=read();
	for (int i=1;i<=n;i++) a[i]=read(),b[i]=read();
	for (int i=1;i<=m;i++){
		e[i].x=read(),e[i].y=read(),e[i].w=read();
		add_edge(e[i].x,e[i].y,e[i].w);add_edge(e[i].y,e[i].x,e[i].w);
		allw+=e[i].w;
	}

	DFS(0);

	printf("%lld\n",ans);
	return 0;
}