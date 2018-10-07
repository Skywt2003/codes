/*
 * XJOI CONTEST1002 T5 期望
 * 180924 By SkyWT
 */

#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<string>

using namespace std;

#define memset_clear(_) memset(_,0,sizeof(_))
#define memset_clear_reg(_) memset(_,-1,sizeof(_))
#define memset_clear_max(_) memset(_,0x3f,sizeof(_))
#define memset_clear_min(_) memset(_,0x80,sizeof(_))
#define sqr(_) ((_)*(_))

#define write(_) cout<<#_<<" = "<<_<<endl
#define write_2(_,__) cout<<#_<<" = "<<_<<" , "<<#__<<" = "<<__<<endl
#define write_3(_,__,___) cout<<#_<<" = "<<_<<" , "<<#__<<" = "<<__<<" , "<<#___<<" = "<<___<<endl

#define int long long

int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=305;
int n,K;
int dst[2][maxn][maxn],cnt[2][maxn];
int ans=0,all=0;

inline void init(){
	memset_clear_max(dst);
	for (int i=0;i<n;i++) dst[0][i][i]=dst[1][i][i]=0;
}

inline void build_cnt(int t){
	for (int k=0;k<n;k++)
	for (int i=0;i<n;i++) if (i!=k)
	for (int j=0;j<n;j++) if (j!=i&&j!=k)
		dst[t][i][j]=min(dst[t][i][j],dst[t][i][k]+dst[t][k][j]);
	for (int i=0;i<n;i++)
	for (int j=0;j<n;j++)
		if (0<dst[t][i][j]&&dst[t][i][j]<K-1) cnt[t][dst[t][i][j]]++,all++;
}

signed main(){
	n=read();K=read();
	init();

	for (int i=1;i<n;i++){
		int x=read();
		dst[0][x][i]=dst[0][i][x]=1;
	}
	build_cnt(0);
	for (int i=1;i<n;i++){
		int x=read();
		dst[1][x][i]=dst[1][i][x]=1;
	}
	build_cnt(1);

	for (int i=1;i<=K-2-1;i++) ans+=cnt[0][i]*cnt[1][K-2-i];
	ans/=2;
	printf("%.10lf\n",(double)ans/(n*(n-1)));
	return 0;
}