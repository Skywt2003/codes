/*
 * XJOI CONTEST1000 T1 左右构造机
 * 180919 By SkyWT
 */

#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define memset_clear(_) memset(_,0,sizeof(_))
#define memset_clear_reg(_) memset(_,-1,sizeof(_))
#define memset_clear_max(_) memset(_,0x3f,sizeof(_))
#define memset_clear_min(_) memset(_,0x80,sizeof(_))
#define sqr(_) ((_)*(_))

using namespace std;
const long long maxn=55,maxlen=105;
long long n;
long long s[maxn],t[maxn],now[maxn],tmp[maxn];

inline void init(){
	for (long long i=1;i<=n;i++) now[i]=s[i];
}

inline bool check(){
	for (long long i=1;i<=n;i++) if (now[i]!=t[i]) return false;
	return true;
}

inline bool make_left(){
	for (long long i=1;i<=n;i++) tmp[i]=now[i];
	for (long long i=1;i<=n;i++){
		now[i]+=tmp[(i>1)?(i-1):n];
		if (now[i]<0) return false;
	}
	return true;
}

inline bool make_right(){
	for (long long i=1;i<=n;i++) tmp[i]=now[i];
	for (long long i=1;i<=n;i++){
		now[i]+=tmp[(i<n)?(i+1):1];
		if (now[i]<0) return false;
	}
	return true;
}

int main(){
	scanf("%lld",&n);
	if (n==0){printf("null\n");return 0;}
	for (long long i=1;i<=n;i++) scanf("%lld",&s[i]),now[i]=s[i];
	for (long long i=1;i<=n;i++) scanf("%lld",&t[i]);
	if (check()){
		printf("null\n");
		return 0;
	}

	// For debug
	// init();
	// for (int i=0;i<4;i++) make_right();
	// for (int i=1;i<=n;i++) printf("%lld\n",now[i]);
	// return 0;

	for (long long i=1;i<=100;i++){
		for (long long j=0;j<=i;j++){
			init();
			bool flg=true;
			for (long long k=1;k<=j;k++) if (!make_left()) flg=false;
			for (long long k=j+1;k<=i;k++) if (!make_right()) flg=false;
			if (flg&&check()){
				for (long long k=1;k<=j;k++) putchar('L');
				for (long long k=j+1;k<=i;k++) putchar('R');
				printf("\n");
				return 0;
			}
		}
	}
	printf("No solution\n");
	return 0;
}