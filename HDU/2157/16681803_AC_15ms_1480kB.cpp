#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

#define int long long
using namespace std;

const int tt=1000;

struct matrix{
	static const int maxn=25;
	int n,m,a[maxn][maxn];

	inline matrix(){memset(a,0,sizeof(a));n=m=0;}

	inline void set_zero(int x,int y){
		n=x;m=y;
		memset(a,0,sizeof(a));
	}

	inline void set_unit(int x,int y){
		n=x;m=y;
		memset(a,0,sizeof(a));
		for (int i=0;i<min(n,m);i++) a[i][i]=1;
	}

	inline matrix operator +(matrix &b){
		matrix ret;ret.set_zero(n,m);
		for (int i=0;i<n;i++)
			for (int j=0;j<m;j++)
				ret.a[i][j]=(a[i][j]+b.a[i][j])%tt;
		return ret;
	}
	
	inline matrix operator -(matrix &b){
		matrix ret;ret.set_zero(n,m);
		for (int i=0;i<n;i++)
			for (int j=0;j<m;j++)
				ret.a[i][j]=(a[i][j]-b.a[i][j]+tt)%tt;
		return ret;
	}

	inline matrix operator *(matrix &b){
		matrix ret;ret.set_zero(n,b.m);
		for (int k=0;k<m;k++)
			for (int i=0;i<n;i++)
				for (int j=0;j<b.m;j++)
					ret.a[i][j]=(ret.a[i][j]+a[i][k]*b.a[k][j]%tt)%tt;
		return ret;
	}
};

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

signed main(){
	for (;;){
		int n=read(),m=read();
		if (n==0&&m==0) break;
		matrix now;now.set_zero(n,n);
		for (int i=0;i<m;i++){
			int x=read(),y=read();
			if (x==y) continue;
			now.a[x][y]=1;
		}

		matrix ans[25];
		ans[0].set_unit(n,n);
		ans[1]=now;
		for (int i=2;i<=20;i++) ans[i]=ans[i-1]*now;

		int T=read();
		while (T--){
			int x=read(),y=read(),k=read();
			printf("%lld\n",ans[k].a[x][y]);
		}
	}
	return 0;
}