/*
 * XJOI CONTEST1000 T5 任务计划
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

const long long maxn=55,maxs=(1<<16)+10,s=1<<16;
long long n;
long long f[maxn][maxs];
struct tasks{
	long long s,t;
};
tasks a[maxn];

inline long long read(){
	long long ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

inline bool compare(tasks aa,tasks bb){
	return aa.t<bb.t;
}

int main(){
	n=read();
	for (long long i=1;i<=n;i++) a[i].s=read();
	for (long long i=1;i<=n;i++) a[i].t=read();
	sort(a+1,a+1+n,compare);
	f[0][0]=1;
	for (long long i=1;i<=n;i++)
	for (long long j=0;j<s;j++){
		for (long long k=a[i].s;k<=a[i].t;k++) if (!(j&(1<<k))) {f[i][j+(1<<k)]+=f[i-1][j];break;}
		f[i][j]+=f[i-1][j];
	}
	long long ans=0;
	for (long long i=0;i<s;i++) ans+=f[n][i];
	printf("%lld\n",ans);
	return 0;
}