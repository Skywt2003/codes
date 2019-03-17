#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

#define int long long
using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=55;
const double eps=1e-5,INF=1.0e9;
int n;
double ans=-1.0;
double f[maxn][maxn][maxn];

//f[i][j][k]: 前 i 个任务，剩余 j 个和 a[i] 不一样的和 k 个和 a[i] 一样的

pair<int,int> tasks[maxn];

bool check(double now){
	for (int i=0;i<=n;i++) for (int j=0;j<=n;j++) for (int k=0;k<=n;k++) f[i][j][k]=INF;
	f[0][0][0]=0.0;
	for (int i=1;i<=n;i++)
	for (int j=0;j<=i;j++)
	for (int k=0;k<=i;k++) if (f[i-1][j][k]!=INF){
		double delta=(double)tasks[i].first-now*(double)tasks[i].second;
		if (tasks[i-1].first==tasks[i].first || i==1){
			f[i][j][k]=min(f[i][j][k],f[i-1][j][k]+delta);
			if (j-1>=0) f[i][j-1][k]=min(f[i][j-1][k],f[i-1][j][k]+delta);
			f[i][j][k+1]=min(f[i][j][k+1],f[i-1][j][k]);
		} else {
			if (j+k<=n) f[i][j+k][0]=min(f[i][j+k][0],f[i-1][j][k]+delta);
			if (j+k-1>=0 && j+k-1<=n) f[i][j+k-1][0]=min(f[i][j+k-1][0],f[i-1][j][k]+delta);
			if (j+k<=n) f[i][j+k][1]=min(f[i][j+k][1],f[i-1][j][k]);
		}
	}
	return f[n][0][0]<0.0;
}

bool cmp(pair<int,int> aa,pair<int,int> bb){
	return aa.first<bb.first;
}

signed main(){
	n=read();
	for (int i=1;i<=n;i++) tasks[i].first=read();
	for (int i=1;i<=n;i++) tasks[i].second=read();
	sort(tasks+1,tasks+1+n,cmp);
	double L=0.0001,R=1.0e8;
	while (L<=R){
		double mid=(L+R)/2.0;
		if (check(mid)) R=mid-eps; else ans=mid,L=mid+eps;
	}
	// printf("%.16f\n",ans);
	printf("%lld\n",(int)ceil(ans*1000.0));
	return 0;
}