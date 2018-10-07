/*
 * Vjudge CONTEST257056 数位DP专题练习
 * C - B-number 
 * 180928 By SkyWT
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

const int maxlen=15;
int n,a[maxlen];
int f[maxlen][maxlen][maxlen][2];

inline int DFS(int i,int now,int yu,bool flag,bool limit){
	// i: 当前需要构造长度  now: 上一位  yu: 之前%13余数  flag: 是否出现13条件  limit: 限制
	if (i==0) return yu?0:1;
	if (f[i][now][yu][flag]!=-1) return f[i][now][yu][flag];
	int cur=0,up=limit?a[i]:9;
	for (int j=0;j<=up;j++) cur+=DFS(i-1,j,(yu-j+13)%13,(now==1&&j==3)?false:flag,j==up);
	return limit?cur:f[i][now][yu][flag]=cur;-+
}

inline void spread_number(int x){
	memset_clear(a);
	while (x) a[++a[0]]=x%10,x/=10;
}

inline int calculate(int x){
	spread_number(x);
	DFS(a[0],0,0,true,true);
}

signed main(){
	memset_clear_reg(f);
	while (~scanf("%lld",&n)) printf("%lld\n",calculate(n));
	return 0;
}