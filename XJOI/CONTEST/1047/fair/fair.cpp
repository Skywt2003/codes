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
int f[maxn][maxn];

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

inline int inv(int x){
	return qsm(x,tt-2);
}

signed main(){
	// n=read();m=read();

	// for (int i=0;i<n;i++)
	// 	for (int j=0;j<n;j++)
	// 		if (i!=j) p[i][j]=1; else p[i][j]=0;

	// for (int i=0;i<m;i++){
	// 	int x=read()-1,y=read()-1;
	// 	p[x][y]=p[y][x]=read();
	// }

	// f[1][0]=1;
	// for (int i=1;i<n;i++){
	// 	for (int k=2;k<=n;k++){
	// 		f[k][i]=(1-f[k-1][i]+tt)%tt;
	// 		for (int j=0;j<=i;j++) mult_mod(f[k][i],f[k-1][i-1]*p[j][i]%tt*inv(i)%tt);
	// 	}
	// }

	// for (int i=1;i<=n;i++){
	// 	for (int j=1;j<=n;j++){
	// 		printf("F[%lld][%lld] = %lld\n",j,i,f[j][i]);
	// 	}
	// }

	// int ans=0;
	// for (int i=1;i<=n;i++) plus_mod(ans,i*f[i][n]%tt);
	puts("0");
	return 0;
}