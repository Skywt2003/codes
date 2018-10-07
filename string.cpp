/*
 * XJOI CONTEST1010
 * T1 随机树
 * 180930 By SkyWT
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
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int tt=1e9+7;
const int maxn=35,maxlen=55;
int n,len[maxn];
char s[maxn][maxlen];

signed main(){
	n=read();
	for (int i=1;i<=n;i++){
		len[i]=read();
		scanf("%s",s[i]);
	}
	int now=0;
	for (;;){
		bool flag=true;
		for (int i=1;i<=n;i++) if (s[i][now%(len[i])]=='X') {flag=false;break;}
		if (flag) break;
		now++;
	}
	long double ans=0.0;
	for (int i=1;i<=50;i++){
		ans=ans+(long double)i/now;
		if (ans>1e9+7) ans-=1e9+7;
	}
	int prt=(int)(ans)%tt;
	printf("%lld\n",prt);
	return 0;
}