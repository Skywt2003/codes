/*
 * Vjudge CONTEST 244508
 * HDU 2065
 * B - "红色病毒"问题
 * 181002 By SkyWT
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

#define int unsigned long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=5,tt=100;
const int transfer[4][4]={{2,1,1,0},
						  {1,2,0,1},
						  {1,0,2,1},
						  {0,1,1,2}};

struct matrix{
	int n,m,a[maxn][maxn];
	void set_identity(){
		memset_clear(a);
		for (int i=0;i<min(n,m);i++) a[i][i]=1;
	}
	void init(){
		memset_clear(a);
	}
	void give(matrix &b){
		b.n=n;b.m=m;
		for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			b.a[i][j]=a[i][j];
	}
	matrix operator +(matrix b){
		if (b.n!=n||b.m!=m) printf("ERROR: TWO DEFFERENT MATRIX MAKE +\n");
		matrix c; c.init();
		c.n=n;c.m=m;
		for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			c.a[i][j]=(a[i][j]+b.a[i][j])%tt;
		return c;
	}
	matrix operator -(matrix b){
		if (b.n!=n||b.m!=m) printf("ERROR: TWO DEFFERENT MATRIX MAKE -\n");
		matrix c; c.init();
		c.n=n;c.m=m;
		for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			c.a[i][j]=(a[i][j]-b.a[i][j]+tt)%tt;
		return c;
	}
	matrix operator *(matrix b){
		if (m!=b.n) printf("ERROR: TWO DEFFERENT MATRIX MAKE *\n");
		matrix c; c.init();
		c.n=n;c.m=b.m;
		for (int i=0;i<  n;i++)
		for (int j=0;j<  m;j++)
		for (int k=0;k<b.m;k++)
			c.a[i][j]=(c.a[i][j]+a[i][k]*b.a[k][j]%tt)%tt;
		return c;
	}
	matrix operator ^(int b){
		matrix ret;ret.n=n;ret.m=m;ret.set_identity();
		matrix w;w.n=n;w.m=m;give(w);
		while (b){
			if (b&1) ret=ret*w;
			w=w*w;b>>=1;
		}
		return ret;
	}
};

signed main(){
	int T=0,n=0;
	scanf("%llu",&T);
	while (T){
		for (int k=0;k<T;k++){
			scanf("%llu",&n);

			matrix now;now.init();
			now.n=1;now.m=4;
			now.a[0][0]=2;now.a[0][1]=now.a[0][2]=1;

			matrix tomul;
			tomul.n=4;tomul.m=4;
			for (int i=0;i<4;i++)
			for (int j=0;j<4;j++)
				tomul.a[i][j]=transfer[i][j];

			tomul=tomul^(n-1);
			now=now*tomul;
			printf("Case %llu: %llu\n",k+1,now.a[0][0]);
		}
		printf("\n");
		scanf("%llu",&T);
	}
	return 0;
}
