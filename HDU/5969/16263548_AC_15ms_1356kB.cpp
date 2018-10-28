/*
 * Vjudge CONTEST 259101
 * D - 最大的位或
 * HDU 5969
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

int T,L,R;

signed main(){
	T=read();
	while (T--){
		L=read();R=read();
		if (L==R) {printf("%lld\n",L);continue;}
		int ans=0;
		for (int i=(int)59;i>=0;i--) if ((L&((int)1<<i))!=(R&((int)1<<i))){
			ans+=((int)1<<(i+1))-(int)1;
			break;
		} else ans+=L&((int)1<<i);
		printf("%lld\n",ans);
	}
	return 0;
}