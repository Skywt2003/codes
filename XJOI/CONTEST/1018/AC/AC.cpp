#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;

#define sqr(_) ((_)*(_))

const double eps=1e-7;

const int maxn=2005;
int n;
double nx,ny,x[maxn],y[maxn];
int fa[maxn];
double ans=0.0,L,R;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

namespace UniSet{
	void init(int n){
		for (int i=1;i<=n;i++) fa[i]=i;
	}
	int getfa(int x){
		if (fa[x]==x) return x;
		fa[x]=getfa(fa[x]);
		return fa[x];
	}
	void merge(int x,int y){
		int fx=getfa(x),fy=getfa(y);
		if (fx!=fy) fa[fx]=fy;
	}
}

inline double get_dist(int i,int j){
	return sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j]));
}

inline bool check(double r){
	r-=eps;
	UniSet::init(n+4);
	for (int i=1;i<=n;i++){
		if (x[i]-r<0.0) UniSet::merge(i,n+1);
		if (x[i]+r>nx) UniSet::merge(i,n+2);
		if (y[i]-r<0.0) UniSet::merge(i,n+3);
		if (y[i]+r>ny) UniSet::merge(i,n+4);
		for (int j=1;j<=n;j++) if (i!=j){
			if (get_dist(i,j)<2*r) UniSet::merge(i,j);
		}
		if (get_dist(i,n+1)<r) return false;
		if (get_dist(i,n+2)<r) return false;
	}
	for  (int i=1;i<=4;i++)
		for (int j=i+1;j<=4;j++)
			if (UniSet::getfa(n+i)==UniSet::getfa(n+j)) return false;
	return true;
}

signed main(){
	freopen("AC.in","r",stdin);
	freopen("AC.out","w",stdout);
	nx=(double)read(),ny=(double)read(),n=read();
	for (int i=1;i<=n;i++) x[i]=(double)read(),y[i]=(double)read();
	x[n+1]=0.0;y[n+1]=0.0;
	x[n+2]=nx;y[n+2]=ny;
	
	L=0.0; R=(double)max(nx,ny);
	while (R-L>eps){
		double mid=(L+R)/2.0;
		if (check(mid)) ans=mid,L=mid+eps; else R=mid-eps;
	}
	printf("%.2lf\n",ans);
	return 0;
}
