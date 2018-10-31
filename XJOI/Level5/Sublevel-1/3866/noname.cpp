#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

#define int long long
using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int tt=1e9+9;
const int maxn=15,maxd=65,maxs=2048+10;
int n,s,a[maxn];
int f[maxd][maxs]; // F[i][j]：剩余 i 位，各个数字被限制情况是 j 的方案数

inline void plus_mod(int &x,int y){
	x=(x+y)%tt;
}

signed main(){
	n=read();s=1<<n;
	for (int i=0;i<n;++i) a[i]=read();
	memset(f,0,sizeof(f));
	f[62][s-1]=1;
	for (int i=62;i>0;--i){
		for (int j=0;j<s;++j){
			for (int k=0;k<=n;k++) if ((k==n) || ((j&((int)1<<k)) && (a[k]&((int)1<<(i-1)))) || (!(j&((int)1<<k)))){ // 枚举当前取 1 的位，或者没有取 1
				int nxt=j;
				for (int t=0;t<n;++t) if ((t!=k) && (j&((int)1<<t)) && (a[t]&((int)1<<(i-1)))) nxt-=(int)1<<t;
				// 原来被限制，而这一位原来是 1 却不得不取 0，则解除限制
				plus_mod(f[i-1][nxt],f[i][j]);
			}
		}
	}
	int ans=0;
	for (int i=0;i<s;i++) plus_mod(ans,f[0][i]);
	printf("%lld\n",ans);
	return 0;
}