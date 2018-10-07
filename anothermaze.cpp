/*
 * XJOI CONTEST1001 T1 又一个迷宫最短路
 * 180920 By SkyWT
 */

#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

#define memset_clear(_) memset(_,0,sizeof(_))
#define memset_clear_reg(_) memset(_,-1,sizeof(_))
#define memset_clear_max(_) memset(_,0x3f,sizeof(_))
#define memset_clear_min(_) memset(_,0x80,sizeof(_))
#define sqr(_) ((_)*(_))

const long long maxn=55;
long long n,a[maxn],sum[maxn];
long long x1,x2,y1,y2;
long long ans=(long long)1<<60;

inline long long read(){
	long long ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

inline long long Abs(long long x){
	return x<0?-x:x;
}

int main(){
	n=read();x1=read()+1,y1=read()+1,x2=read()+1,y2=read()+1;
	for (long long i=1;i<=n;i++) a[i]=read(),sum[i]=sum[i-1]+a[i];
	if (y1==y2){
		printf("%lld\n",sum[max(x1,x2)]-sum[min(x1,x2)-1]);
		return 0;
	}
	for (long long i=1;i<=n;i++){
		long long now=a[i]*(Abs(y1-y2)-1);
		now+=(i>x1)?(sum[i]-sum[x1-1]):(sum[x1]-sum[i-1]);
		now+=(i>x2)?(sum[i]-sum[x2-1]):(sum[x2]-sum[i-1]);
		ans=min(ans,now);
	}
	printf("%lld\n",ans);
	return 0;
}