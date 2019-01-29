#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

#define double long double
#define int long long

#define sqr(x) ((x)*(x))
const double pi=3.14159265358979323846;
const double INF=1.0e15;
const double eps=1.0e-15;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=100005;

int n,x,y;
int xx[maxn],yy[maxn];
double maxd=0.0,mind=INF;

inline double max(double x,double y){
	return x<y?y:x;
}

inline double min(double x,double y){
	return x<y?x:y;
}

double get_dist(double x1,double y1,double x2,double y2){
	return sqrt(sqr(x1-x2)+sqr(y1-y2));
}

double get_line_dist(double x,double y,double x1,double y1,double x2,double y2){
	if (x1>x2) swap(x1,x2),swap(y1,y2);
	double xs,ys;
	if (y1==y2){
		ys=y1;
		xs=x;
	} else if (x1==x2){
		xs=x1;
		ys=y;
	} else {
		double k1=(y1-y2)/(x1-x2);
		double b1=y1-k1*x1;
		double k2=((double)-1.0)/k1;
		double b2=y-k2*x;
		xs=(b2-b1)/(k1-k2);
		ys=k1*xs+b1;
	}
	if ((xs>=x1-eps && xs<=x2+eps && ys>=y1-eps && ys<=y2+eps) || 
	    (xs>=x1-eps && xs<=x2+eps && ys<=y1+eps && ys>=y2-eps)) return get_dist(x,y,xs,ys); else return INF;
}

signed main(){
	n=read();x=read();y=read();
	for (int i=1;i<=n+1;i++){
		if (i<=n) xx[i]=read(),yy[i]=read(); else xx[i]=xx[1],yy[i]=yy[1];
		maxd=max(maxd,get_dist(x,y,xx[i],yy[i]));
		mind=min(mind,get_dist(x,y,xx[i],yy[i]));
		if (i!=1) mind=min(mind,get_line_dist(x,y,xx[i],yy[i],xx[i-1],yy[i-1]));
	}
	printf("%.18Lf\n",pi*(sqr(maxd)-sqr(mind)));
	return 0;
}