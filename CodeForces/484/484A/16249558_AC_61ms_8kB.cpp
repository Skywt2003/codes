/*
 * Vjudge CONTEST 259101
 * B - Bits
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

int T,L,R,ans_cnt,ans_num;

inline int count(int x){
	int cnt=0;
	while (x) cnt+=x&1,x>>=1;
	return cnt;
}

inline int lowbit(int x){
	return x&(-x);
}

signed main(){
	T=read();
	while (T--){
		L=read();R=read();
		ans_cnt=count(L);ans_num=L;
		while (L<=R){
			L+=lowbit(~L);
			int now_cnt=count(L);
			if (L<=R && (now_cnt>ans_cnt || (now_cnt==ans_cnt && L<ans_num))) ans_cnt=now_cnt,ans_num=L;
		}
		printf("%lld\n",ans_num);
	}
	return 0;
}