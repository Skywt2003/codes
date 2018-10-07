/*
 * Vjudge CONTEST257056 数位DP专题练习
 * A - 不要62
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

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

#define int long long
const int INF=(long long)1<<60;

const int maxn=15;
int n,m;
int a[maxn],f[maxn][maxn];

inline void spread_number(int x){
	memset_clear(a);
	while (x) a[++a[0]]=x%10,x/=10;
}

inline void build_dp(){
	for (int i=0;i<=9;i++) if (i!=4) f[1][i]=1;
	for (int i=2;i<=8;i++)
	for (int j=0;j<=9;j++) if (j!=4)
	for (int k=0;k<=9;k++) if (k!=4){
		if (j==6&&k==2) continue;
		f[i][j]+=f[i-1][k];
	}
}

inline int calculate(int x){
	spread_number(x);
	int ret=0;
	for (int i=a[0];i>=1;i--){
		for (int j=0;j<a[i];j++) if (j!=4){
			if (j==2&&a[i+1]==6) continue;
			ret+=f[i][j];
		}
		if (a[i]==4||(a[i]==2&&a[i+1]==6)) break;
	}
	return ret;
}

signed main(){
	build_dp();
	n=read();m=read();
	while (n||m){
		printf("%lld\n",calculate(m+1)-calculate(n));
		n=read();m=read();
	}
	return 0;
}