#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

#define int long long

const int maxn=505,maxm=105;

int n,m,W,q;
int INF;
int f[maxn][maxm];
int sum[maxn][maxm];

struct gong{
	int x,t;
};
gong a[maxn];

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

signed main(){
	n=read();m=read();W=read();
	for (int i=1;i<=m;i++) a[i].x=read(),a[i].t=read();
	q=read();
	for (int i=1;i<=q;i++){
		int x=read(),ki=read();
		sum[x][ki]++;
	}
	for (int j=1;j<=m;j++)
		for (int i=1;i<=n;i++)
			sum[i][j]+=sum[i-1][j];
	
	memset(f,0x3f,sizeof(f));INF=f[0][0];
	for (int i=1;i<=m;i++) f[0][i]=0;
	for (int i=0;i<=n;i++){
		for (int j=1;j<=m;j++) if (i+a[j].x<=n){
			for (int k=1;k<=m;k++){
				if (sum[i+a[j].x][j]-sum[i][j]==0) f[i+a[j].x][j]=min(f[i+a[j].x][j],f[i][k]+a[j].t+((j==k)?(0):(W)));
			}
		}
	}
	int ans=INF;
	for (int i=1;i<=m;i++) ans=min(ans,f[n][i]);
	printf("%lld\n",(ans==INF)?-1:ans);
	return 0;
}