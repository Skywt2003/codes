/*
 * XJOI CONTEST 1014
 * T1 - 平衡串
 * SelfJudge
 * 181006 By SkyWT
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

#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=105;
int n=1;
int sum1=0,sum2=0;
int cnt[256];
char a[maxn][maxn];

signed main(){
	while (~scanf("%s",a[n])) n++;
	n--;
	for (int i=1;i<=n;i++){
		int len=strlen(a[i]);
		for (int j=1;j<len;j++) if (a[i][j]!=a[i][j-1]) sum1++;
		for (int j=0;j<len;j++) sum2+=cnt[a[i][j]];
		for (int j=0;j<len;j++) cnt[a[i][j]]++;
	}
	if (sum1==sum2) printf("Accepted\n"); else return 1;
	return 0;
}