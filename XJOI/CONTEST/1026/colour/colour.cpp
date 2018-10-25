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
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;
#define int long long
const int maxn=305,INF=(long long)1<<61;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int T,n;
int a[maxn],b[maxn];
int f[maxn][maxn][maxn];
int cnt,num[maxn],id[100005];

inline int min3(int x,int y,int z){
	int ret=x;
	if (y<ret) ret=y;
	if (z<ret) ret=z;
	return ret;
}

inline int min(int x,int y){
	if (x<y) return x; else return y;
}

inline void init(){
	memset(f,0x3f,sizeof(f));
	cnt=0;
}

inline void make_id(){
	sort(b+1,b+1+n);
	for (int i=1;i<=n;){
		int j=i;
		while (j+1<=n && b[j+1]==b[i]) j++;
		id[b[i]]=++cnt;num[cnt]=b[i];i=j+1;
	}
}

inline void solve(){
	for (int i=1;i<=n;i++) f[i][i][id[a[i]]]=0;
	for (int L=1;L<n;L++){
		for (int i=1;i<=n-L+1;i++){
			int j=i+L;
			for (int k=1;k<=cnt;k++){
				int t=id[a[i]],w=id[a[j]];
				f[i][j][k]=min3(f[i][j][k],f[i+1][j][k]+((k==t)?(0):(num[k]*a[i])), f[i][j-1][k]+((k==w)?(0):(num[k]*a[j])));
				f[i][j][t]=min(f[i][j][t],f[i+1][j][k]+((t==k)?(0):(num[k]*a[i]*(j-i))));
				f[i][j][w]=min(f[i][j][w],f[i][j-1][k]+((w==k)?(0):(num[k]*a[j]*(j-i))));
			}
		}
	}
}

signed main(){
	T=read();
	while (T--){
		init();
		n=read();
		for (int i=1;i<=n;i++) a[i]=b[i]=read();
		make_id();
		solve();
		int ans=INF;
		for (int i=1;i<=cnt;i++) ans=min(ans,f[1][n][i]);
		printf("%lld\n",ans);
		// for (int i=1;i<=n;i++){
		// 	for (int j=i;j<=n;j++){
		// 		for (int k=1;k<=cnt;k++) printf("F[%lld][%lld][%lld] = %lld\n",i,j,k,f[i][j][k]);
		// 	}
		// }
	}
	return 0;
}