/*
*XJOI CONTEST 1014
*T2-加法与乘法（20）
*181017 By SkyWT
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

const int INF=1e18;
int S,T,a,b;
int ans=INF;
int f[200];

inline int qsm(int a,int b){
	int ret=1,w=a;
	while (b){
		if (b&1) ret*=w;
		w*=w;b>>=1;
	}
	return ret;
}

signed main(){
	S=read(),T=read(),a=read(),b=read();
	if (S==T) return printf("0\n"),0;
	if (!a&&!b) {
		if (!T) return printf("1\n"),0; else return printf("-1"),0;
	} else if (!a&&b) {
		if ((a==0&&b==1)||!S) return printf("-1"),0;
		for(int mul=1,tmp=0;S*mul<=T;mul*=b,tmp++) if(S*mul==T) ans=min(ans,tmp);
		printf("%lld\n",(ans==INF)?-1:ans);
	} else if (a&&!b) {
		if (T>=S&&(T-S)%a==0) return printf("%lld\n",(T-S)/a),0;
		if (T%a==0) return printf("%lld\n",T/a+1),0;
		printf("-1\n");
	} else {
		int flag=0;
		if (b==1) {
			if ((T-S)%a==0&&T>=S) return printf("%lld\n",(T-S)/a),0; else return printf("-1\n"),0;
		} else if (!S) S+=a,flag=1;
		for (int mul=1,tmp=0;S*mul<=T;mul*=b,tmp++) {
			int now=tmp,delta=T-S*mul;
			f[tmp]=mul;
			if (delta%a) continue;
			delta/=a;
			for (int i=tmp;i!=-1;i--) now+=delta/f[i],delta%=f[i];
			ans=min(ans,now);
		}
		printf("%lld\n",(ans==INF)?-1:(ans+flag));
	}
	return 0;
}