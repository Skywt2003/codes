#include<bits/stdc++.h>

#define int long long
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
double ans=1e14;

void add_edge(int x,int y,int z){
	tot++; to[tot]=y; w[tot]=z;
	nxt[tot]=lnk[x]; lnk[x]=tot;
}

double gnow=0;

void get_answer(int x,int fa,double now){
	gnow+=c[x]*sqr(now);
	for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=fa) get_answer(to[i],x,now+w[i]);
}

signed main(){
	freopen("problem3.in","r",stdin);
	#ifndef DEBUG
		freopen("problem30.out","w",stdout);
	#endif
	n=read();
	for (int i=1;i<=n;i++) c[i]=read();
	for (int i=1;i<n;i++){
		int x=read(),y=read(),z=read();
		add_edge(x,y,z);add_edge(y,x,z);
	}
	
	for (int i=1;i<=n;i++){
		gnow=0.0;
		get_answer(i,-1,0);
		ans=min(ans,gnow);
	}
	
	printf("%.3lf\n",ans);
	return 0;
}
