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

const int maxn=2005;
int n,sum[maxn];
int all_sum=0,all_cnt=0;

inline void make_answer(int step){
	if (step==n){
		all_cnt++;int now=0;
		for (int i=0;i<n;i++) now+=sqr(sum[i]);
		all_sum+=now;
		return;
	}
	for (int i=0;i<step;i++){
		sum[i]++;sum[step]++;
		make_answer(step+1);
		sum[i]--;sum[step]--;
	}
}

signed main(){
	n=read();
	make_answer(1);
	printf("%.2lf\n",(double)all_sum/(double)all_cnt);
	// cout<<"ALL_SUM = "<<all_sum<<endl;
	return 0;
}