#include<bits/stdc++.h>

#define int long long
//#define double long double
#define sqr(_) ((_)*(_))

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=2e5+5,maxe=4e5+5;

int n,c[maxn];
int tot=0,lnk[maxn],nxt[maxe],to[maxe],w[maxe];
int fa[maxn],siz[maxn];

double sum2[maxn],sum[maxn]; // sum of nodes which is in subtree
double ans=1e25;

void add_edge(int x,int y,int z){
	tot++; to[tot]=y; w[tot]=z;
	nxt[tot]=lnk[x]; lnk[x]=tot;
}

void build_tree(int x){
	siz[x]=c[x];
	for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=fa[x]){
		fa[to[i]]=x;
		build_tree(to[i]);
		siz[x]+=siz[to[i]];
	}
}

void build_sub(int x){
	for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=fa[x]){
		build_sub(to[i]);
		sum[x]+=sum[to[i]] + siz[to[i]]*w[i];
		sum2[x]+=sum2[to[i]] + 2.0*w[i]*sum[to[i]] + siz[to[i]]*sqr(w[i]);
	}
}

void get_answer(int x,double now2,double now,int cnt){
	ans=min(ans,sum2[x]+now2);
	
	for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=fa[x]){
		double ncnt = cnt+c[x];
		double ncnto = siz[x]-siz[to[i]]-c[x]; // Other subtrees
		double nxt = now + ncnt*w[i];
		double nxto = sum[x]-(sum[to[i]]+w[i]*siz[to[i]]) + w[i]*ncnto;
		double nxt2 = now2 + 2.0*w[i]*now + cnt*sqr(w[i]) + c[x]*sqr(w[i]);
		double nxt2o = (sum2[x]-(sum2[to[i]]+2.0*w[i]*sum[to[i]]+siz[to[i]]*sqr(w[i])))
						+ 2.0*w[i]*(sum[x]-(sum[to[i]]+w[i]*siz[to[i]]))
						+ ncnto*sqr(w[i]);
		get_answer(to[i], nxt2+nxt2o, nxt+nxto, ncnt+ncnto);
	}
}

signed main(){
	freopen("problem3.in","r",stdin);
	freopen("problem3.out","w",stdout);
	
	n=read();
	for (int i=1;i<=n;i++) c[i]=read();
	for (int i=1;i<n;i++){
		int x=read(),y=read(),z=read();
		add_edge(x,y,z);add_edge(y,x,z);
	}
	
	build_tree(1);
	
	build_sub(1);
	
	get_answer(1,0,0,0);
	
	printf("%.3lf\n",ans);
	return 0;
}
