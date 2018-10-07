/*
 * Vjudge CONTEST257056 数位DP专题练习
 * B - Bomb
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

int T,n;
int f[25][11],a[25];

inline void make_dp(){
	for (int i=0;i<=9;i++) f[1][i]=1;
	for (int i=2;i<=22;i++)
	for (int j=0;j<=9;j++)
	for (int k=0;k<=9;k++){
		if (j==4&&k==9) continue;
		f[i][j]+=f[i-1][k];
	}
}

inline void spread_number(int x){
	memset_clear(a);
	while (x) a[++a[0]]=x%10,x/=10;
}

inline int calculate(int x){
	int ret=0;
	spread_number(x);
	for (int i=a[0];i>=1;i--){
		for (int j=0;j<a[i];j++) ret+=f[i][j];
		if (a[i]==9&&a[i+1]==4) break;
	}
	return ret;
}

signed main(){
	make_dp();
	T=read();
	while (T--){
		n=read();
		printf("%lld\n",n+1-calculate(n+1));
	}
	return 0;
}