/*
 * XJOI CONTEST 1014
 * T2 - 加法与乘法（20）
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

const int INF=(int)1<<60;
int S,T,a,b;
int ans=INF;

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
	if (S==T){
		printf("0\n");
		return 0;
	}
	if (S>T && b==0){
		if (a==0) printf("-1\n"); else
		if (T%a) printf("-1\n"); else
		printf("%lld\n",T/a+1);
		return 0;
	}
	if (b==0 || b==1){
		if (a==0) {printf(T==0?"1\n":"-1\n");return 0;}
		if ((T-S)%a) printf("-1\n"); else printf("%lld\n",(T-S)/a);
		return 0;
	}
	if (a==0){
		if (T%S || T/S%b) printf("-1\n"); else printf("%lld\n",(int)((double)log(T/S)/log(b)));
		return 0;
	}
	for (int k=0;k<=18;k++){
		int x=qsm(b,k);
		if (S*x>T) break; else
		if (S*x==T){
			ans=min(ans,k);
			break;
		} else {
			int delta=T-S*x,now=k;
			if (delta%a) continue;
			delta/=a;
			for (int i=k;i>=0;i--){
				int q=qsm(b,i);
				now+=delta/q;delta%=q;
			}
			ans=min(ans,now);
		}
	}
	if (ans<0 || ans==INF) printf("-1\n"); else printf("%lld\n",ans);
	return 0;
}