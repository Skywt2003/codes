#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=10;
const double INF=1e8;
double x[maxn],y[maxn];
double xx[maxn],yy[maxn];
double minx=INF,maxx=-(INF),miny=INF,maxy=-(INF);

inline bool inc(double x,double L,double R){
	if (x>=min(L,R)-1e-7 && x<=max(L,R)+1e-7) return true;
	return false;
}

signed main(){
	for (int i=0;i<4;i++) x[i]=read(),y[i]=read(),minx=min(minx,x[i]),maxx=max(maxx,x[i]),miny=min(miny,y[i]),maxy=max(maxy,y[i]);
	for (int i=0;i<4;i++) xx[i]=read(),yy[i]=read();

	bool aflg=true;
	for (int i=0;i<4;i++){
		if (xx[i]<minx || xx[i]>maxx || yy[i]<miny || yy[i]>maxy) {aflg=false;break;}
	}
	if (aflg){
		cout<<"YES"<<endl;
		return 0;
	}

	minx=INF,maxx=-(INF),miny=INF,maxy=-(INF);
	aflg=true;
	for (int i=0;i<4;i++) minx=min(minx,xx[i]),maxx=max(maxx,xx[i]),miny=min(miny,yy[i]),maxy=max(maxy,yy[i]);
	for (int i=0;i<4;i++){
		if (x[i]<minx || x[i]>maxx || y[i]<miny || y[i]>maxy) {aflg=false;break;}
	}
	if (aflg){
		cout<<"YES"<<endl;
		return 0;
	}

	for (int i=0;i<4;i++){
		int j=(i+1)%4;
		for (int ii=0;ii<4;ii++){
			int jj=(ii+1)%4;
			double k=1.0*(yy[ii]-yy[jj])/(xx[ii]-xx[jj]);
			double b=1.0*yy[ii] - k*xx[ii];
			if (x[i]==x[j] && inc(x[i],xx[ii],xx[jj])){
				double nowy=k*x[i]+b;
				if (inc(nowy,y[i],y[j]) && inc(nowy,yy[ii],yy[jj])){
					cout<<"YES"<<endl;
					return 0;
				}
			}
			if (y[i]==y[j] && inc(y[i],yy[ii],yy[jj])){
				double nowx=(1.0*y[i]-b)/k;
				if (inc(nowx,x[i],x[j]) && inc(nowx,xx[ii],xx[jj])){
					cout<<"YES"<<endl;
					return 0;
				}
			}
		}
	}
	cout<<"NO"<<endl;
	return 0;
}