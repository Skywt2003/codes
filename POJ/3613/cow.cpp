// #pragma GCC optimize(3)

#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

// #define int long long
using namespace std;

// const int INF=0x3f3f3f3f3f3f3f3f;
const int INF=0x3f3f3f3f;

struct matrix{
	static const int maxn=105;
	int n,m,a[maxn][maxn];

	inline void set_zero(int x,int y){
		n=x;m=y;
		memset(a,0,sizeof(a));
	}

	inline void set_unit(int x,int y){
		n=x;m=y;
		memset(a,0,sizeof(a));
		for (int i=0;i<min(n,m);i++) a[i][i]=1;
	}

	inline void set_infi(int x,int y){
		n=x;m=y;
		memset(a,0x3f,sizeof(a));
		// for (int i=0;i<min(n,m);i++) a[i][i]=0;
	}

	inline matrix operator *(matrix &b){
		matrix ret;ret.set_infi(n,b.m);
		for (int k=0;k<m;k++)
			for (int i=0;i<n;i++)
				for (int j=0;j<b.m;j++)
					ret.a[i][j]=min(ret.a[i][j],a[i][k]+b.a[k][j]);
		return ret;
	}

	inline matrix operator ^(int b){
		matrix ret;ret=*this;b--;
		matrix w;w=*this;
		while (b){
			if (b&1) ret=ret*w;
			b>>=1;w=w*w;
		}
		return ret;
	}
};

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int N,T,S,E;
int id[1005];

signed main(){
	N=read();T=read();S=read();E=read();
	matrix now;now.set_infi(101,101);
	for (int i=1;i<=T;i++){
		int len=read(),x=read(),y=read();
		if (!id[x]) id[x]=++id[0];
		if (!id[y]) id[y]=++id[0];
		// if (x==y) continue;
		now.a[id[x]][id[y]]=now.a[id[y]][id[x]]=min(now.a[id[x]][id[y]],len);
	}
	now=now^N;
	// for (int i=1;i<100;i++)
	// 	for (int j=1;j<100;j++) if ((id[i]) && (id[j]) && i!=j && ans.a[id[i]][id[j]]!=INF)
	// 		printf("%lld to %lld = %lld\n",i,j,ans.a[id[i]][id[j]]);
	printf("%d\n",now.a[id[S]][id[E]]);
	return 0;
}