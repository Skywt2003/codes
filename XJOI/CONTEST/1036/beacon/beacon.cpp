#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

#define int long long
using namespace std;

const int maxn=20,INF=0x3f3f3f3f3f3f3f3f;
int n,ans=INF;
int tot=0,lnk[maxn],nxt[2*maxn],son[2*maxn];
int dst[maxn][maxn];

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

inline void add_edge(int x,int y){
	tot++;son[tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}

inline int count(int x){
	int ret=0;
	while (x) ret+=(x&1),x>>=1;
	return ret;
}

inline bool check(int x){
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++) if(i!=j){
			bool flg=false;
			for (int k=0;k<n;k++) if ((x&(1<<k)) && dst[i][k]!=dst[j][k]) {flg=true;break;}
			if (!flg) return false;
		}
	}
	return true;
}

inline void build_dist(int s,int now,int fa){
	for (int i=lnk[now];i;i=nxt[i]) if (son[i]!=fa) dst[s][son[i]]=dst[s][now]+1,build_dist(s,son[i],now);
}

signed main(){
	freopen("beacon.in","r",stdin);
	freopen("beacon.out","w",stdout);
	n=read();
	for (int i=1;i<n;i++){
		int x=read(),y=read();
		add_edge(x-1,y-1);add_edge(y-1,x-1);
	}
	for (int i=0;i<n;i++) build_dist(i,i,-1);
	for (int i=0;i<((int)1<<n);i++){
		int cnt=count(i);
		if (cnt>=ans) continue;
		if (check(i)) ans=cnt;
	}
	printf("%lld\n",ans);
	return 0;
}