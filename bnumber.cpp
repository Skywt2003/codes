/*
 * WRONG CODE. GIVE UP.
 * Vjudge CONTEST257056 数位DP专题练习
 * C - B-number 
 * 180927 By SkyWT
 */

#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<map>

using namespace std;

#define memset_clear(_) memset(_,0,sizeof(_))
#define memset_clear_tre(_) memset(_,1,sizeof(_))
#define memset_clear_reg(_) memset(_,-1,sizeof(_))
#define memset_clear_max(_) memset(_,0x3f,sizeof(_))
#define memset_clear_min(_) memset(_,0x80,sizeof(_))
#define sqr(_) ((_)*(_))

#define write(_) cout<<#_<<" = "<<_<<endl
#define write_2(_,__) cout<<#_<<" = "<<_<<" , "<<#__<<" = "<<__<<endl
#define write_3(_,__,___) cout<<#_<<" = "<<_<<" , "<<#__<<" = "<<__<<" , "<<#___<<" = "<<___<<endl

#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=15;
int n;
int a[maxn],f[maxn][maxn][maxn]; // F[i][j][k]: i 位，首位 j，模 13 余 k

inline int qsm(int a,int b){
	int ret=1,w=a;
	while (b){
		if (b&1) ret=ret*w;
		w=w*w;b>>=1;
	}
	return ret;
}

inline void make_dp(){
	for (int i=0;i<=9;i++) f[1][i][i]=1;
	for (int i=2;i<=15;i++){
		for (int j=0;j<=9;j++)
		for (int k=0;k<=9;k++)
		for (int t=0;t<13;t++){
			if (j==1&&k==3) continue;
			f[i][j][(t+j*qsm(10,i))%13]+=f[i-1][k][t];
		}
	}
}

inline void spread_number(int x){
	memset_clear(a);
	while (x) a[++a[0]]=x%10,x/=10;
}

inline int calculate(int x){
	spread_number(x);
	int lst=0,ret=0;
	for (int i=a[0];i>=1;i--){
		for (int j=0;j<a[i];j++)
		for (int k=0;k<13;k++)
			if ((lst+k)%13) ret+=f[i][j][k];
		// if (a[i+1]==1&&a[i]==3) break;
		lst+=a[i]*qsm(10,i-1);
	}
	return ret;
}

signed main(){
	make_dp();
	while (~scanf("%lld",&n)){
		printf("%lld\n",n+1-calculate(n+1));
	}
	return 0;
}