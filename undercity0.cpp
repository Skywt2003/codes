/*
 * XJOI CONTEST1011
 * T1 UnderCity（暴力）
 * 181003 By SkyWT
 */

#pragma GCC diagnostic error "-std=c++11"
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

const int maxn=5005,maxe=10005;
int n,value[maxn];
int tot=0,lnk[maxn],nxt[maxe],son[maxe],deep[maxn];
int sum[maxn],f[maxn][20];
bool vis[maxn];

inline void add(int x,int y){
	tot++;son[tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}

inline int build_deep(int x,int fa){
	for (int i=lnk[x];i;i=nxt[i]) if (son[i]!=fa) deep[son[i]]=deep[x]+1,build_deep(son[i],x);
}

inline void build_lca(){
	for (int i=1;i<=n;i++) f[i][0]=i;
	for (int j=1;j<20;j++)
	for (int i=1;i<=n;i++)
		f[i][j]=f[f[i][j-1]][j-1];
}

inline int lca(int x,int y){
	if (deep[x]>deep[y]) swap(x,y);
	for (int j=19;j>=1;j--) if (deep[f[y][j]]<=deep[x]) y=f[y][j];
	if (x==y) return x;
	for (int i=19;i>=1;i--) if (f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	x=f[x][0],y=f[y][0];
	return x;
}

inline void DFS(int x,int fa){
	for (int i=lnk[x];i;i=nxt[i]) if (son[i]!=fa) DFS(son[i],x),sum[x]+=sum[son[i]];
}

signed main(){
	n=read();
	for (int i=1;i<=n;i++) value[i]=read();
	for (int i=1;i<n;i++){
		int x=read(),y=read();
		add(x,y);add(y,x);
	}
	deep[1]=1;build_deep(1,-1);
	build_lca();
	vector <int> vec;
	for (int i=1;i<=n;i++){
		vec.clear();
		for (int j=1;j<=n;j++) if (deep[j]>deep[i] && value[j]<value[i]) vec.push_back(j);
		for (int j=0;j<vec.size();j++)
		for (int k=0;k<vec.size();k++) if (j!=k && value[vec[j]]<value[vec[k]]){
			int l=lca(vec[j],vec[k]);
			sum[(deep[j]>deep[i])?i:j]++;
		}
	}
	DFS(1,-1);
	for (int i=1;i<n;i++) printf("%lld ",sum[i]);
	printf("%lld\n",sum[n]);
	return 0;
}