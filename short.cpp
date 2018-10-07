/*
 * Vjudge CONTEST 259101
 * A - Short Program
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

const int maxn=5e5+10;
int n;
struct opt{
	char ch;
	bool x;
}a[10][maxn];

bool flg=true;
int ans[10],num[10],stt[2][10];
bool hav[10];

inline bool build01(int id,int step){
	// id：这是第几位； value：当前值
	if (step==ans[0]){
		bool now=false;
		for (int i=1;i<=ans[0];i++){
			if (ans[step+1]==0) now&=(bool)hav[i]; else
			if (ans[step+1]==1) now|=(bool)hav[i]; else now^=(bool)hav[i];
		}
		if (now!=stt[0][id]) return false;
		now=true;
		for (int i=1;i<=ans[0];i++){
			if (ans[step+1]==0) now&=(bool)hav[i]; else
			if (ans[step+1]==1) now|=(bool)hav[i]; else now^=(bool)hav[i];
		}
		if (now!=stt[1][id]) return false;
		return true;
	}
	for (int i=0;i<2;i++){
		hav[step+1]=i;
		if (build01(id,step+1)) return true;
	}
	return false;
}

inline bool check(){
	printf("%lld , ",ans[0]);for (int i=1;i<=ans[0];i++) printf("%lld ",ans[i]);printf("\n");
	for (int i=0;i<10;i++){ // 对于每一位都要验证成立
		if (!build01(i,0)) return false; else {
			for (int j=1;j<=ans[0];j++) num[i]+=(int)hav[i]<<(j-1);
		}
	}
	return true;
}

inline void build_xulie(int step){
	if (!flg) return;
	if (step>5) return;
	if (check()) {flg=false;return;}
	for (int i=0;i<3;i++) if (flg){
		ans[step+1]=i;
		ans[0]=step+1;
		build_xulie(step+1);
	} else break;
}

signed main(){
	n=read();
	for (int i=1;i<=n;i++){
		char now=read_ch();
		int x=read();
		for (int j=0;j<10;j++) a[j][i]=(opt){now,(bool)(x&(1<<j))};
	}
	for (int i=0;i<10;i++){ // 构造“标准状态”
		stt[0][i]=0;stt[1][i]=1;
		for (int j=1;j<=n;j++){
			if (a[i][j].ch=='&') stt[0][i]&=a[i][j].x,stt[1][i]&=a[i][j].x; else
			if (a[i][j].ch=='|') stt[0][i]|=a[i][j].x,stt[1][i]|=a[i][j].x; else
			if (a[i][j].ch=='^') stt[0][i]^=a[i][j].x,stt[1][i]^=a[i][j].x;
		}
	}

	build_xulie(0);

	if (flg) return printf("NO SOLUTION...\n"),0;
	printf("%lld\n",ans[0]);
	for (int i=1;i<=ans[0];i++){
		if (ans[i]==0) putchar('&'); else
		if (ans[i]==1) putchar('|'); else
		if (ans[i]==2) putchar('^');
		printf(" %lld\n",num[i]);
	}
	return 0;
}