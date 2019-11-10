#include<bits/stdc++.h>

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1005;

int n,m,l,r;
double f[maxn][maxn];
double V,v[maxn];

signed main(){
	freopen("pigeon.in","r",stdin);
	freopen("pigeon.out","w",stdout);
	n=read(); m=read(); l=read(); r=read(); V=read();
	for (int i=1;i<=n;i++) v[i]=read();
	
	f[n+1][m]=V;
	for (int i=n;i>=1;i--){
		double now=0.0;
		for (int j=l;j<=r;j++) now+=f[i+1][j];
		for (int j=0;j<=m;j++){
			f[i][j]=max(f[i+1][j]+v[i],now/(r-l+1));
			if (j<m) now=now+f[i+1][min(j+r+1,m)]-f[i+1][min(j+l,m)];
		}
	}
	printf("%.3lf\n",f[1][0]);
	return 0;
}
