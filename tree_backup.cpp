/*
 * XJOI CONTEST 1013
 * T2 - tree
 * 181005 By SkyWT
 */

#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<map>

using namespace std;

#define memset_clear(_) memset(_,0,sizeof(_))
#define memset_clear_tre(_) memset(_,1,sizeof(_))
#define memset_clear_reg(_) memset(_,-1,sizeof(_))
#define memset_clear_max(_) memset(_,0x3f,sizeof(_))
#define memset_clear_min(_) memset(_,0x80,sizeof(_))
#define sqr(_) ((_)*(_))

#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=3005,maxe=6005;
int n,p,q,f[maxn];
int ff[maxn][13];
int tot=0,lnk[maxn],nxt[maxe],son[maxe];
int cnt[maxn],deep[maxn];
int ans=0;

inline void add(int x,int y){
	tot++;son[tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}

inline void build_lca(){
	for (int j=1;j<13;j++)
	for (int i=1;i<=n;i++)
		ff[i][j]=ff[ff[i][j-1]][j-1];
}

inline int get_lca(int x,int y){
	if (deep[x]<deep[y]) swap(x,y);
	for (int i=12;i>=0;i--) if (deep[ff[x][i]]>=deep[ff[y][i]]) x=ff[x][i];
	if (x==y) return x;
	for (int i=12;i>=0;i--) if (ff[x][i]!=ff[y][i]) x=ff[x][i],y=ff[y][i];
	return ff[x][0];
}



inline void build_deep(int x,int fa,bool flg){
	cnt[deep[x]]++;
	if ((flg)&&(fa!=-1)) ff[x][0]=fa;
	for (int i=lnk[x];i;i=nxt[i]) if (son[i]!=fa){
		deep[son[i]]=deep[x]+1;
		build_deep(son[i],x);
	}
}

inline void build_dp(int x,int fa,int sub){
	f[x]=cnt[deep[x]+sub];
	for (int i=lnk[x];i;i=nxt[i]) if (son[i]!=fa){
		build_dp(son[i],x,sub);
		f[x]+=f[son[i]];
	}
}

signed main(){
	n=read();p=read();q=read();
	for (int i=1;i<n;i++){
		int x=read(),y=read();
		add(x,y);add(y,x);
	}

	build_deep(1,-1,true);
	build_lca();
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++) if (i!=j){
		
	}


	for (int i=1;i<=n;i++){
		memset_clear(cnt);
		deep[i]=1;
		build_deep(i,-1,false);
		build_dp(i,-1,p);
		int son_sum=0;
		for (int j=lnk[i];j;j=nxt[j]) son_sum+=f[son[i]];
		for (int j=1;j<=n;j++) if (deep[j]-deep[i]==q)
			ans+=son_sum-f[j]+ (f[j]-cnt[deep[j]+p]);

		printf("I=%lld;\n",i);
		printf("I=   ");for (int j=1;j<=n;j++) printf("% lld",j);printf("\n");
		printf("DEEP=");for (int j=1;j<=n;j++) printf("% lld",deep[j]);printf("\n");
		printf("F=   ");for (int j=1;j<=n;j++) printf("% lld",f[j]);printf("\n");
		printf("\n");
	}
	printf("%lld\n",ans);
	return 0;
}