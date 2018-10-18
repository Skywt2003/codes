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
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;
#define int long long
#define sqr(_) ((_)*(_))

const int tt=998244353;
const int maxn=1005,maxe=2005;
int n,a[maxn],d[maxn],f[maxn];
int tot=0,lnk[maxn],nxt[maxe],son[maxe],p[maxn];
int fa[maxn];
int ans=0;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

inline void add(int x,int y,int z){
	tot++;son[tot]=y;p[tot]=z;
	nxt[tot]=lnk[x];lnk[x]=tot;
}

inline int qsm(int a,int b){
	int ret=1,w=a;
	while (b){
		if (b&1) ret=ret*w%tt;
		w=w*w%tt;b>>=1;
	}
	return ret;
}

inline void build_tree(int x){
	for (int i=lnk[x];i;i=nxt[i]) if (son[i]!=fa[x]){
		fa[son[i]]=x;
		build_tree(son[i]);
	}
}

inline void build_f(){
	for (int i=1;i<=n;i++){
		int now=i;f[i]=(f[i]+a[i])%tt;
		for (int j=1;j<=d[i];j++){
			now=fa[now];
			if (now==0) break;
			f[now]=(f[now]+a[i])%tt;
		}
	}
}

inline void make_answer(int x,int nfa,int pn){
	ans=(ans+f[x]*pn%tt)%tt;
	for (int i=lnk[x];i;i=nxt[i]) if (son[i]!=nfa){
		if (p[i]==0) continue;
		make_answer(son[i],x,pn*p[i]%tt);
	}
}

signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=read();
	for (int i=1;i<=n;i++) a[i]=read(),d[i]=read();
	for (int i=1;i<n;i++){
		int x=read(),y=read(),z=read();
		add(x,y,z);add(y,x,z);
	}
	fa[1]=-1;
	build_tree(1);
	build_f();
	int q=read();
	while (q--){
		int x=read();
		ans=0;
		make_answer(x,-1,1);
		printf("%lld\n",sqr(ans)%tt);
	}
	return 0;
}