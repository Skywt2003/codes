#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>

#define clear(_) memset(_,0,sizeof(_))
using namespace std;
const int maxn=20005,maxm=277;
int T,n,m,f[2][305][305],sum[maxn];

/*
 * F[0/1][i][j]: 轮到 Alice/Bob 拿，轮到第 i 个物品，上一次对方拿了 j，差值的最大/最小值
 * 状态转移：
 * > F[0][i][j] = max( F[1][i+j][j]+sum[i+j-1]-sum[i-1], F[1][i+j+1][j+1]+sum[i+j]-sum[i-1] )
 * > F[1][i][j] = min( F[0][i+j][j]-sum[i+j-1]+sum[i-1], F[0][i+j+1][j+1]-sum[i+j]+sum[i-1] )
 */

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

int main(){
	T=read();
	while (T--){
		n=read();
		m=sqrt(2.0*n+1);
		for (int i=1;i<=n;i++) sum[i]=sum[i-1]+read();
		clear(f);
		for (int i=n;i>=1;i--){
			for (int j=m;j>=1;j--){
				if (i+j-1<=n) f[0][i%maxm][j]=f[1][(i+j)%maxm][j]+sum[i+j-1]-sum[i-1],
							  f[1][i%maxm][j]=f[0][(i+j)%maxm][j]-sum[i+j-1]+sum[i-1];
				if (i+j<=n) f[0][i%maxm][j]=max(f[0][i%maxm][j],f[1][(i+j+1)%maxm][j+1]+sum[i+j]-sum[i-1]),
							f[1][i%maxm][j]=min(f[1][i%maxm][j],f[0][(i+j+1)%maxm][j+1]-sum[i+j]+sum[i-1]);
			}
		}
		printf("%d\n",f[0][1][1]);
	}
	return 0;
}