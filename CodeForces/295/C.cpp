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

const int maxn=105,maxk=5005;

int n,k,num50=0,num100=0;
int f[maxn][maxn][2*maxn];
int inv[maxn],fac[maxn];

const int tt=1000000007;

inline void build_c(){
	inv[0]=1;inv[1]=1;
	for (int i=2;i<=n*2;i++) inv[i]=tt-tt/i*inv[tt%i]%tt;
	fac[0]=1;
	for (int i=1;i<=n*2;i++) fac[i]=fac[i-1]*i%tt;
}

inline int C(int x,int y){
	if (y==1) return x;
	// printf("C (%lld, %lld) = %lld\n",x,y,fac[x]*inv[y]%tt*inv[x-y]%tt);
	return fac[x]*inv[y]%tt*inv[x-y]%tt;
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

	memset(f,0,sizeof(f));
	f[num50][num100][0]=1;
	for (int kk=0;kk<=2*n;kk++){
		if (f[1][0][kk]){
			printf("%lld\n%lld\n",kk*2-1,f[1][0][kk]*inv[num50]%tt);
			return 0;
		}
		if (f[0][1][kk]){
			printf("%lld\n%lld\n",kk*2-1,f[0][1][kk]*inv[num100]%tt);
			return 0;
		}
		for (int i=0;i<=num50;i++)
		for (int j=0;j<=num100;j++) if (f[i][j][kk])
		for (int w=0;w<=j;w++){
			int t=min((k-w*100)/50,i);
			if (k>=50 ) for (int bck=1;bck<=min(num50-i+t,k/50);bck++)
				f[i-t+bck][j-w][kk+1]=(f[i-t+bck][j-w][kk+1]+f[i][j][kk]*C(i,t)%tt*C(j,w)%tt*C(num50-i+t,bck)%tt)%tt;
			if (k>=100) for (int bck=1;bck<=min(num100-j+w,k/100);bck++)
				f[i-t][j-w+bck][kk+1]=(f[i-t][j-w+bck][kk+1]+f[i][j][kk]*C(i,t)%tt*C(j,w)%tt*C(num100-j+w,bck)%tt)%tt;
		}
	}
	printf("-1\n0\n");
	return 0;
}