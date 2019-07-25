#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1005;
int T,n,a[maxn][maxn];
int suml[maxn][maxn],sumc[maxn][maxn];
bool f[maxn][maxn]; // F[i][j]: 轮到左上角 (i,j) 的矩阵局面是否赢

int getSumLine(int x,int i,int j){return suml[x][j]-suml[x][i-1];}
int getSumColm(int x,int i,int j){return sumc[j][x]-sumc[i-1][x];}

signed main(){
	T=read();
	while (T--){
		n=read();
		for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++){
			a[i][j]=read();
			suml[i][j]=suml[i][j-1]+a[i][j];
			sumc[i][j]=sumc[i-1][j]+a[i][j];
		}
		memset(f,0,sizeof(f));
		for (int i=1;i<=n;i++){
			if ((getSumLine(1,1,i)&1)==0) f[1][i]=true;
			if ((getSumColm(1,1,i)&1)==0) f[i][1]=true;
		}

		for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) if (!f[i][j]){
			if ((f[i-1][j]==false) && (getSumLine(i,1,j)&1)==0) f[i][j]=true;
			if ((f[i][j-1]==false) && (getSumColm(j,1,i)&1)==0) f[i][j]=true;
		}
		printf(f[n][n]?"W\n":"L\n");
	}
	return 0;
}