#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1e5+5,INF=2e9+5;
double eps=1e-7;
int n;
struct point{
	int x,y;
}a[maxn];
double ans=0.0;

int max_l[maxn],min_l[maxn],max_r[maxn],min_r[maxn];

bool cmp_x(point aa,point bb){
	return aa.x<bb.x;
}

void build_max_min(){
	for (int i=0;i<=n+1;i++) max_l[i]=max_r[i]=-INF,min_l[i]=min_r[i]=INF;
	max_l[1]=min_l[1]=a[1].y;
	for (int i=2;i<=n;i++)   max_l[i]=max(max_l[i-1],a[i].y),min_l[i]=min(min_l[i-1],a[i].y);
	max_r[n]=min_r[n]=a[n].y;
	for (int i=n-1;i>=1;i--) max_r[i]=max(max_r[i+1],a[i].y),min_r[i]=min(min_r[i+1],a[i].y);
}

bool check(double d){
	int j=1;
	for (int i=1;i<=n;i++){
		if (j<i) j=i;
		while (j+1<=n && (double)a[j+1].x-a[i].x <= 2*d) j++;
		if ((double)max(max_l[i-1],max_r[j+1])-min(min_l[i-1],min_r[j+1]) <= 2*d) return true;
	}
	// printf("check faild: mid=%.12f\n",d);
	return false;
}

signed main(){
	n=read();
	for (int i=1;i<=n;i++){
		int x=read(),y=read();
		a[i].x=x-y;
		a[i].y=x+y;
	}
	sort(a+1,a+1+n,cmp_x);
	build_max_min();
	double L=0.0,R=2*1.0e9;
	while (L<=R){
		double mid=(R-L)/2.0+L;
		if (check(mid)) ans=mid,R=mid-eps; else L=mid+eps;
	}
	printf("%.12lf\n",ans);
	return 0;
}