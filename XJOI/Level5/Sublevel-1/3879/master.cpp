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
#include<queue>

#define int long long
using namespace std;

const int prime[4]={2333, 19260817, 19550701, 1e9+7};
int tt=1e9+7;

struct matrix{
	static const int maxn=55;
	int n,m,a[maxn][maxn];

	matrix(){
		memset(a,0,sizeof(a));n=m=0;
	}

	void set_zero(int x,int y){
		n=x;m=y;
		memset(a,0,sizeof(a));
	}

	void set_unit(int x,int y){
		n=x;m=y;
		memset(a,0,sizeof(a));
		for (int i=0;i<min(n,m);i++) a[i][i]=1;
	}

	bool operator ==(matrix &b){
		if (n!=b.n || m!=b.m) return false;
		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++){
				if (a[i][j]!=b.a[i][j]) return false;
			}
		}
		return true;
	}

	bool operator !=(matrix &b){
		return !(*this == b);
	}

	matrix operator +(matrix &b){
		matrix ret;ret.set_zero(n,m);
		for (int i=0;i<n;i++){
			for (int j=0;j<m;j++){
				ret.a[i][j]=(a[i][j]+b.a[i][j])%tt;
			}
		}
		return ret;
	}
	
	matrix operator -(matrix &b){
		matrix ret;ret.set_zero(n,m);
		for (int i=0;i<n;i++){
			for (int j=0;j<m;j++){
				ret.a[i][j]=(a[i][j]-b.a[i][j]+tt)%tt;
			}
		}
		return ret;
	}

	matrix operator *(matrix &b){
		matrix ret;ret.set_zero(n,b.m);
		for (int k=0;k<m;k++){
			for (int i=0;i<n;i++){
				for (int j=0;j<b.m;j++){
					ret.a[i][j]=(ret.a[i][j]+a[i][k]*b.a[k][j]%tt)%tt;
				}
			}
		}
		return ret;
	}

	matrix operator ^(int b){
		matrix ret;ret.set_unit(n,m);
		matrix w;w=*this;
		while (b){
			if (b&1) ret=ret*w;
			b>>=1;w=w*w;
		}
		return ret;
	}

	int count_sum(){
		int ret=0;
		for (int i=0;i<n;i++){
			for (int j=0;j<m;j++){
				ret=(ret+a[i][j])%tt;
			}
		}
		return ret;
	}
};

int n;

signed main(){
	scanf("%lld",&n);
	matrix chg;chg.set_zero(n,n);
	char ch=getchar();while (ch<'0'||ch>'9') ch=getchar();
	for (int i=1;i<=n;i++){
		for (;;){
			bool flg=true;
			int now=0;
			while (ch>='0'&&ch<='9') now=now*10+ch-'0',ch=getchar();
			while (ch<'0'||ch>'9'){
				if (ch==10||ch==13||ch==-1) {flg=false;break;}
				ch=getchar();
			}
			chg.a[i-1][now-1]++;
			// printf("%lld -> %lld ++\n",i,now);
			if (flg==false && i==n) break;
			while (ch<'0'||ch>'9') ch=getchar();
			if (flg==false) break;
		}
	}

	matrix now;now.set_zero(1,n);
	now.a[0][0]=1;

	matrix result1;matrix result2;
	matrix tmp1,tmp2;
	for (int i=0;i<4;i++){
		tt=prime[i];
		tmp1=chg^(1e9);
		tmp2=chg^(2e9);
		result1=now*tmp1;
		result2=now*tmp2;
		if (result1.count_sum()!=result2.count_sum()){
			printf("-1\n");
			return 0;
		}
	}
	int ans=result1.count_sum();
	printf("%lld\n",ans);
	return 0;
}