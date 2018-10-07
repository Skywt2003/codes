/*
 * XJOI CONTEST1001 T3 合并括号序列
 * 180920 By SkyWT
 */

#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

#define memset_clear(_) memset(_,0,sizeof(_))
#define memset_clear_reg(_) memset(_,-1,sizeof(_))
#define memset_clear_max(_) memset(_,0x3f,sizeof(_))
#define memset_clear_min(_) memset(_,0x80,sizeof(_))
#define sqr(_) ((_)*(_))

#define write(_) cout<<#_<<" = "<<_<<endl;

const int maxn=2505,tt=1e9+7;
int n,m;
char s1[maxn],s2[maxn];
int sum1[maxn],sum2[maxn];
int f[maxn][maxn];

inline void plus_mod(int &x,int y){
	x=(x+y)%tt;
}

int main(){
	scanf("%s",s1+1);n=strlen(s1+1);
	scanf("%s",s2+1);m=strlen(s2+1);
	for (int i=1;i<=n;i++) sum1[i]=sum1[i-1]+(s1[i]=='('?1:-1);
	for (int i=1;i<=m;i++) sum2[i]=sum2[i-1]+(s2[i]=='('?1:-1);
	f[0][0]=1;
	for (int i=0;i<=n;i++)
	for (int j=0;j<=m;j++){
		if (i==n&&j==m) continue;
		if (!((s1[i+1]==')')&&(sum1[i]+sum2[j]==0))) plus_mod(f[i+1][j],f[i][j]);
		if (!((s2[j+1]==')')&&(sum1[i]+sum2[j]==0))) plus_mod(f[i][j+1],f[i][j]);
	}
	printf("%d\n",f[n][m]);
	return 0;
}