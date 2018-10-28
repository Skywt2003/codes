/*
 * Vjudge CONTEST244508 矩阵乘法专题训练
 * POJ 3233
 * C - Matrix Power Series
 * 180929 By SkyWT
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

// #define int long long

const int maxn=35;
int n,k,tt;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

struct matrix{
	int a[maxn][maxn];
	void init(){ // 构造一个单位矩阵
		memset(a,0,sizeof(a));
		for (int i=0;i<n;i++) a[i][i]=1;
	}
	void clear(){
		memset(a,0,sizeof(a));
	}
	matrix operator +(matrix b){
		matrix c;c.clear();
		for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			c.a[i][j]=a[i][j]+b.a[i][j];
		return c;
	}
	matrix operator *(matrix b){
		matrix c; c.clear();
		for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
		for (int k=0;k<n;k++)
			c.a[i][j]=(c.a[i][j]+a[i][k]*b.a[k][j]%tt)%tt;
		return c;
	}
	matrix operator ^(int b){
		matrix ret; ret.init();
		matrix w;   w.clear();
		for (int i=0;i<2;i++)
		for (int j=0;j<2;j++)
			w.a[i][j]=a[i][j];
		while (b){
			if (b&1) ret=ret*w;
			w=w*w;b>>=1;
		}
		return ret;
	}
}fst;

struct matrix_matrix{
	matrix a[3][3];
	void init(matrix number,bool flag){
		if (flag){
			a[0][0].init();a[1][1].init();
			a[0][1].clear();a[1][0].clear();
		} else {
			a[0][0]=a[0][1]=number;
			a[1][0].clear();a[1][1].init();
		}
	}
	void clear(){
		a[0][0].clear();a[0][1].clear();
		a[1][0].clear();a[1][1].clear();
	}
	matrix_matrix operator *(matrix_matrix b){
		matrix_matrix c; c.clear();
		for (int i=0;i<2;i++)
		for (int j=0;j<2;j++)
		for (int k=0;k<2;k++)
			c.a[i][j]=(c.a[i][j]+a[i][k]*b.a[k][j]);
		return c;
	}
	matrix_matrix operator ^(int b){
		matrix tmp;
		matrix_matrix ret;ret.init(tmp,true);
		matrix_matrix w;w.init(fst,false);
		while (b){
			if (b&1) ret=ret*w;
			w=w*w;b>>=1;
		}
		return ret;
	}
	void write(){
		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++) printf("%d ",a[0][1].a[i][j]%tt);
			printf("\n");
		}
	}
};

signed main(){
	n=read();k=read();tt=read();
	for (int i=0;i<n;i++)
	for (int j=0;j<n;j++)
		fst.a[i][j]=read()%tt;
	matrix_matrix now;
	now.init(fst,false);
	now=now^k;
	now.write();
	return 0;
}

