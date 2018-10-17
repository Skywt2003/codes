/*
 * XJOI CONTEST 1015
 * T3 - 初等数论 (My SpecialJudge)
 * 181008 By SkyWT
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

const int maxn=605;
int n=0;
int a[maxn];

inline int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}

signed main(){
	int x;
	while (~scanf("%lld",&x)) a[++n]=x;
	for (int i=2;i<=n;i++) if (gcd(a[i],a[i-1])!=1){
		printf("Failed\n");
		printf("GCD( A[%lld],A[%lld] ) = %lld\n",i-1,i,gcd(a[i],a[i-1]));
		return 0;
	}
	for (int i=3;i<=n;i++)
	for (int j=1;j<=i-2;j++) if (gcd(a[i],a[j])==1){
		printf("Failed\n");
		printf("GCD( A[%lld],A[%lld] ) = 1\n",j,i);
		return 0;
	}
	printf("Accepted\n");
	return 0;
}