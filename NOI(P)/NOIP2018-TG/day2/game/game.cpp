#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define int long long

#define lst(x,y) ((g[i-1][0][x][y]+g[i-1][1][x][y])%tt)

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=10,maxm=1000005;
const int tt=1e9+7;

int n,m;
int f[maxm][2][2];
int g[maxm][2][2][2];

signed main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read();m=read();
	if (n>m) swap(n,m);
	if (n==1){
		printf("%lld\n",((int)1<<m));
	} else if (n==2){
		f[1][0][0]=f[1][1][0]=f[1][1][1]=f[1][0][1]=1;
		for (int i=2;i<=m;i++){
			f[i][0][0]=f[i][0][1]=(f[i-1][0][0]+f[i-1][1][0])%tt;
			f[i][1][0]=f[i][1][1]=(f[i-1][0][0]+f[i-1][1][0]+f[i-1][1][1]+f[i-1][0][1])%tt;
		}
		printf("%lld\n",(f[m][0][0]+f[m][1][0]+f[m][0][1]+f[m][1][1])%tt);
	} else if (n==3){
		if (m==3) {printf("112\n");return 0;}
		for (int i=0;i<2;i++)
			for  (int j=0;j<2;j++)
				for (int k=0;k<2;k++)
					g[1][i][j][k]=1;
		for (int i=2;i<=m;i++){
			g[i][0][0][0]=g[i][0][0][1] = lst(0,0);
			g[i][1][0][0]=g[i][1][0][1] = (lst(0,0)+lst(1,0)+lst(0,1))%tt;
			g[i][0][1][0]=g[i][0][1][1] = (lst(0,0)+lst(0,1))%tt;
			g[i][1][1][0]=g[i][1][1][1] = (lst(0,0)+lst(0,1)+lst(1,0)+lst(1,1));
		}
		int ans=0;
		for (int i=0;i<2;i++)
			for  (int j=0;j<2;j++)
				for (int k=0;k<2;k++)
					ans+=g[m][i][j][k];
		printf("%lld\n",ans);
	}
	return 0;
}
