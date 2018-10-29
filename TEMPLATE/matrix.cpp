#include<bits/stdc++.h>
using namespace std;
const int tt=19260817;

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