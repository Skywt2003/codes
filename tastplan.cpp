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

long long n,f[51][70000],out;
struct point{
	long long st,ed;
}
point p[100];
bool cmp(point a,point b){
	return a.ed<b.ed;
}
 
int main(){
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++)scanf("%lld",&p[i].st);
	for(long long i=1;i<=n;i++)scanf("%lld",&p[i].ed);
	sort(p+1,p+1+n,cmp);
	f[0][0]=1;
	for(long long i=1;i<=n;i++)
		for(long long j=0;j<(1<<16);j++){
			for(long long k=p[i].st;k<=p[i].ed;k++) if(((1<<k)&j)==0){
				f[i][j|(1<<k)]+=f[i-1][j];
				break;
			}
			f[i][j]+=f[i-1][j];
		}
	}
	for(long long i=0;i<(1<<16);i++) out+=f[n][i];
	printf("%lld",out);
	return 0;
}