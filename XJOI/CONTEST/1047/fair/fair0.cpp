#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#define int long long

using namespace std;
const int maxn=20,maxs=(1<<14)+10;
const int tt=998244353;

int n,m,s;
int p[maxn][maxn];

int f[maxn][maxs];

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

inline int qsm(int a,int b){
	int ret=1,w=a%tt;
	while (b){
		if (b&1) ret=ret*w%tt;
		w=w*w%tt;b>>=1;
	}
	return ret;
}

inline void plus_mod(int &x,int y){
	x=(x+y)%tt;
}

inline void mult_mod(int &x,int y){
	x=(x*y)%tt;
}

signed main(){
	freopen("fair.in","r",stdin);
	freopen("fair.out","w",stdout);
	n=read();m=read();s=1<<n;

	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			if (i!=j) p[i][j]=1; else p[i][j]=0;
	for (int i=0;i<n;i++) f[1][1<<i]=1;

	for (int i=0;i<m;i++){
		int x=read()-1,y=read()-1;
		p[x][y]=p[y][x]=read();
	}

	for (int j=1;j<s;j++){
		for (int i=1;i<=n;i++) if (f[i][j]){
			for (int t=0;t<n;t++) if (j&(1<<t)){
				for (int k=0;k<n;k++) if ((j&(1<<k))==false){
					plus_mod(f[i][j+(1<<k)],(1-p[t][k]+tt)%tt*f[i][j]%tt);
					mult_mod(f[i+1][j+(1<<k)],p[t][k]*f[i][j]%tt);
				}
			}
		}
	}

	for (int i=1;i<=n;i++){
		for (int j=0;j<s;j++){
			printf("F[%lld][%lld] = %lld\n",i,j,f[i][j]);
		}
	}

	int ans=0;
	for (int i=1;i<=n;i++) plus_mod(ans,i*f[i][s-1]%tt);
	printf("%lld\n",ans);
	return 0;
}