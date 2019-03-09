#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<cmath>

#define int long long
using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=45;

int n,q;

struct matrix{
	int n,m;
	double a[maxn][maxn];

	matrix(){memset(a,0,sizeof(a));n=m=0;}
	void set_zero(int x,int y){n=x;m=y;memset(a,0,sizeof(a));}
	void set_unit(int x,int y){n=x;m=y;memset(a,0,sizeof(a));for (int i=0;i<min(n,m);i++) a[i][i]=1;}

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
				ret.a[i][j]=(a[i][j]+b.a[i][j]);
			}
		}
		return ret;
	}
	
	matrix operator -(matrix &b){
		matrix ret;ret.set_zero(n,m);
		for (int i=0;i<n;i++){
			for (int j=0;j<m;j++){
				ret.a[i][j]=(a[i][j]-b.a[i][j]);
			}
		}
		return ret;
	}

	matrix operator *(matrix &b){
		matrix ret;ret.set_zero(n,b.m);
		for (int k=0;k<m;k++){
			for (int i=0;i<n;i++){
				for (int j=0;j<b.m;j++){
					ret.a[i][j]=(ret.a[i][j]+a[i][k]*b.a[k][j]);
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
};

double x[maxn],y[maxn];

map<pair<double,double> , bool> used;
int line_cnt=0;
struct line{
	double k,b;
	vector<int> dots;
}lines[maxn*maxn];
vector<int> pass_lines[maxn];

matrix A[maxn];

void build_A1(){
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			double k=((y[j]-y[i])/(x[j]-x[i])); double b=y[i]-k*x[i];
			if (!used[make_pair(k,b)]) used[make_pair(k,b)]=true; else continue;

			line_cnt++;
			lines[line_cnt].k=k;lines[line_cnt].b=b;
			for (int t=1;t<=n;t++) if (k*x[t]+b==y[t]) lines[line_cnt].dots.push_back(t),pass_lines[t].push_back(line_cnt);
		}
	}
	for (int i=1;i<=n;i++) sort(pass_lines[i].begin(),pass_lines[i].end());
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			int ii=0,jj=0;
			while (ii<(int)pass_lines[i].size() && jj<(int)pass_lines[j].size()){
				if (pass_lines[i][ii]<pass_lines[j][jj]) ii++; else
				if (pass_lines[i][ii]>pass_lines[j][jj]) jj++; else {
					int nowl=pass_lines[i][ii];
					A[0].a[i][j]+=1.0/(int)lines[nowl].dots.size();
					A[0].a[j][i]+=1.0/(int)lines[nowl].dots.size();
					ii++;jj++;
				}
			}
		}
	}
}

void build_A2k(){
	for (int i=2;i<=log2(10001);i++){
		
	}
}

matrix get_mul(int x){

}

void make_answer(int x){

}

int get_answer(int x){

}

signed main(){
	n=read();
	for (int i=1;i<=n;i++) x[i]=read(),y[i]=read();
	build_A1();
	build_A2k();
	q=read();
	for (int i=1;i<=q;i++){
		int s=read(),m=read();
		make_answer(s);
		printf("%lld\n",get_answer(m));
	}
}