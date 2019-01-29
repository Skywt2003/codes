#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=55,maxk=5005;

int n,k,num50=0,num100=0;
int f[maxn][maxn][4*maxn][2];
int fac[4*maxn],inv[4*maxn];

const int tt=1000000007;

inline int qsm(int a,int b){
	int ret=1,w=a;
	while (b){
		if (b&1) ret=ret*w%tt;
		w=w*w%tt;b>>=1;
	}
	return ret;
}

inline void build_c(){
	fac[0]=1;
	for (int i=1;i<=n*4;i++) fac[i]=fac[i-1]*i%tt;
	inv[4*n]=qsm(fac[4*n],tt-2);
	for(int i=4*n-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%tt;
}

inline int C(int x,int y){
	return fac[x]*inv[y]%tt*inv[x-y]%tt;
}

inline void plus_mod(int &x,int y){
	x=(x+y)%tt;
}

signed main(){
	n=read();k=read();
	build_c();
	int all_sum=0;
	for (int i=1;i<=n;i++){
		int x=read();all_sum+=x;
		if (x==50) num50++; else num100++;
	}
	if (all_sum <= k){
		printf("1\n1\n");
		return 0;
	} else {
		if (k<50 && (num50>0||num100>0)) {printf("-1\n0\n");return 0;} else
		if (k<100 && num100>0) {printf("-1\n0\n");return 0;}
	}

	f[num50][num100][0][1]=1;
	for (int kk=1;kk<=4*n;kk++){
		for (int i=0;i<=num50;i++)
		for (int j=0;j<=num100;j++) if (i!=0 || j!=0){
			for (int t=0;t<=i;t++)
			for (int w=0;w<=j;w++){
				if (w*100+t*50>k || w+t==0) continue;
				plus_mod(f[i-t][j-w][kk][0],f[i][j][kk-1][1]*C(i,t)%tt*C(j,w)%tt);
			}
			for (int t=0;t<=num50-i;t++)
			for (int w=0;w<=num100-j;w++){
				if (w*100+t*50>k || w+t==0) continue;
				plus_mod(f[i+t][j+w][kk][1],f[i][j][kk-1][0]*C(num50-i,t)%tt*C(num100-j,w)%tt);
			}
		}
		if (f[0][0][kk][0]){
			printf("%lld\n%lld\n",kk,f[0][0][kk][0]);
			return 0;
		}
	}
	printf("-1\n0\n");
	return 0;
}