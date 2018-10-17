#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")

#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

#define int long long
#define sqr(_) ((_)*(_))

const int maxn=2005;
int n,nx,ny,x[maxn],y[maxn];
int fa[maxn];
int ans=0;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

struct info{
	int x,y,dst;
};
vector<info> vec;

inline int min4(int a,int b,int c,int d){
	int ret=a;
	if (b<ret) ret=b;
	if (c<ret) ret=c;
	return d<ret?d:ret;
}

inline bool compare(info aa,info bb){
	return aa.dst<bb.dst;
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
		// printf("Merged: %lld %lld\n",x,y);
		int fx=getfa(x),fy=getfa(y);
		if (fx!=fy) fa[fx]=fy;
	}
}

inline double get_dist(int i,int j){
	return sqrt(sqr(((double)x[i]-x[j])/2.0)+sqr(((double)y[i]-y[j])/2.0));
}

inline bool check(){
	if (UniSet::getfa(n+1)==UniSet::getfa(n+2)) return false;
	if (UniSet::getfa(n+3)==UniSet::getfa(n+4)) return false;
	if (UniSet::getfa(n+1)==UniSet::getfa(n+3)) return false;
	if (UniSet::getfa(n+2)==UniSet::getfa(n+4)) return false;
	return true;
}

signed main(){
	// freopen("AC.in","r",stdin);
	// freopen("AC.out","w",stdout);
	nx=read(),ny=read();
	n=read();
	for (int i=1;i<=n;i++) x[i]=read(),y[i]=read();

	vec.clear();
	for (int i=1;i<n;i++)
		for (int j=i+1;j<=n;j++)
			vec.push_back((info){i,j,get_dist(i,j)*1000});
	for (int i=1;i<=n;i++){
		vec.push_back((info){i,n+1,x[i]*1000});
		vec.push_back((info){i,n+2,(nx-x[i])*1000});
		vec.push_back((info){i,n+3,y[i]*1000});
		vec.push_back((info){i,n+4,(ny-y[i])*1000});
	}

	UniSet::init(n+4);
	sort(vec.begin(),vec.end(),compare);
	for (int i=1;i<=n;i++) x[i]*=1000,y[i]*=1000;

	nx*=1000,ny*=1000;

	for (int i=0;i<vec.size();i++){
		int ii=vec[i].x,jj=vec[i].y;
		if (UniSet::getfa(ii)==UniSet::getfa(jj)){
			ans=vec[i].dst;
			continue;
		}
		UniSet::merge(ii,jj);
		if (!check()) {ans=vec[i].dst-1;break;}
	}

	printf("%.2lf\n",(double)ans/1000);
	return 0;
}