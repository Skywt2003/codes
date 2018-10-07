/*
 * CodeForces CONTEST 1060
 * A Phone Numbers
 * 181004 By SkyWT
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

inline char read_ch(){
	char ch=getchar();
	while (ch!='|'&&ch!='^'&&ch!='&') ch=getchar();
	return ch;
}

const int maxn=105;
int n,cnt[10];
char a[maxn];

signed main(){
	n=read();
	scanf("%s",a);
	for (int i=0;i<n;i++) cnt[a[i]-'0']++;
	int sum1=cnt[8];
	int sum2=0;
	for (int i=0;i<10;i++) if (i!=8) sum2+=cnt[i];
	printf("%lld\n",min(sum2/8,sum1));
	return 0;
}