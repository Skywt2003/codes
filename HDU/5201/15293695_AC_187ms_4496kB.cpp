/*
 * 共 n 个桃 m 只猴
 * F[i][j]: i 个桃子分给 j 只猴子方案数
 * 隔板法：F[i][j]=C[i+j-1][j-1]
 * 
 * 选 k 只猴子，比第一只猴子分到桃子**不严格多**
 * 这 k+1 只猴子预先分 x 个桃子
 * 那么方案数是 C[m-1][k]*F[n-(k+1)*x][m-1]
 * 
 * 180808
 */
#define LL long long
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=200010,tt=1e9+7;
int T,n,m;
LL fac[maxn],inv[maxn];
LL ans=0;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
inline LL qsm(int a,int b){
	LL ret=1,w=a%tt;
	while (b){
		if (b&1) ret=(LL)ret*w%tt;
		b>>=1;w=(LL)w*w%tt;
	}
	return ret;
}
inline void Build(){
	fac[0]=1;
	for (int i=1;i<=maxn-5;i++) fac[i]=(LL)fac[i-1]*i%tt;
	inv[0]=1;
	for (int i=1;i<=maxn-5;i++) inv[i]=qsm(fac[i],tt-2);
}
inline LL C(int n,int m){
	if (n<m||n<0||m<0) return 0;
	return (LL)fac[n]*inv[n-m]%tt*inv[m]%tt;
}
inline LL F(int x,int y){
	return C(x+y-1,y-1);
}

int main(){
	Build();
	T=read();
	for (int i=1;i<=T;i++){
		n=read();m=read();ans=0;
		if (n==1||m==1) {printf("1\n");continue;}
		for (int x=1;x<=n;x++){
			// ans=(ans+C(n-i+m-2,m-2))%tt;
			int t=(n-x+m-2)/(m-1);
			if (x<=t) continue;
			for (int k=0;n-(k+1)*x>=0;k++){
				LL now=C(m-1,k)*F(n-(k+1)*x,m-1)%tt;
				if (k&1) ans=(ans-now+tt)%tt; else ans=(ans+now)%tt;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}