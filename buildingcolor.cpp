/*
 * XJOI CONTEST1004 T5 楼的颜色
 * 180922 By SkyWT
 */

#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<string>

using namespace std;

#define memset_clear(_) memset(_,0,sizeof(_))
#define memset_clear_reg(_) memset(_,-1,sizeof(_))
#define memset_clear_max(_) memset(_,0x3f,sizeof(_))
#define memset_clear_min(_) memset(_,0x80,sizeof(_))
#define sqr(_) ((_)*(_))

#define write(_) cout<<#_<<" = "<<_<<endl
#define write_2(_,__) cout<<#_<<" = "<<_<<" , "<<#__<<" = "<<__<<endl
#define write_3(_,__,___) cout<<#_<<" = "<<_<<" , "<<#__<<" = "<<__<<" , "<<#___<<" = "<<___<<endl

#define int long long
const int tt=1e9+7;
const int N=1296;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1296+10,maxcolor=1296+10;
int n,k,a[maxn];
int color[maxn];
int f[maxn][maxn]; // 用完第 i 种颜色后，存在 j 次“颜色变化”的排列数
int inv[maxn],fact[maxn];

inline void plus_mod(int &x,int y){
	x=(x+y)%tt;
}

inline void build_inverse(){
	inv[0]=1;inv[1]=1;
	for (int i=2;i<=N;i++) inv[i]=(tt-tt/i)*inv[tt%i]%tt;
	for(int i=1;i<=N;i++) inv[i]=inv[i-1]*inv[i]%tt;
}
inline void build_fact(){
	fact[0]=1;
	for (int i=1;i<=N;i++) fact[i]=i*fact[i-1]%tt;
}

inline int C(int x,int y){ // C(n,m)=n!/(n-m)!m!
	return fact[x]*inv[x-y]%tt*inv[y]%tt;
}

inline int qsm(int a,int b){
	int ret=1,w=a%tt;
	while (b){
		if (b&1) ret=ret*w%tt;
		b>>=1;w=(w*w)%tt;
	}
	return ret;
}

signed main(){
	n=read();k=read();
	build_inverse();
	build_fact();
	for (int i=1;i<=n;i++) a[i]=read(),color[a[i]]++;
	f[0][0]=1;
	int count=0;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=k;j++){
			// 楼房分为两类
			// 一类：考虑插入原来形成的同色楼中, 颜色+2            有 count-1-(j-1)  个空隙, 插入 x 楼房
			// 二类：考虑插入原来的"颜色间隙"里 (包括两边), 颜色+1  有 2+j-1 个空隙, 插入 color[i]-x 楼房
			int can1=count-1-(j-1),can2=(j>1)?(2+j-1):(1);
			if (j==1){ // 针对只有二类的情况特判
				plus_mod(f[i][j],f[i-1][j-1]*fact[color[i]]*qsm(can2,color[i])%tt);
			} else for (int x=0;x<=color[i];x++){ // 枚举“一类”楼房数量
				plus_mod(f[i][j],f[i-1][j-2]*C(color[i],x)%tt*fact[x]%tt*qsm(can1,x)%tt);
				plus_mod(f[i][j],f[i-1][j-1]*C(color[i],color[i]-x)%tt*fact[color[i]-x]*qsm(can2,color[i]-x)%tt);
			}
		}
		count+=color[i];
	}
	printf("%lld\n",f[n][k]);
	return 0;
}