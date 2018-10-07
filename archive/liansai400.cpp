/*
 * XJOI CONTEST1002 T1 联赛400分题
 * 180923 By SkyWT
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
const int tt=1e9+7;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxc=15,maxn=105,maxe=5005,maxs=(1<<10)+10;
int n,m;
int color[maxn],x[maxn],y[maxn];
int tot=0,lnk[maxn],nxt[maxe],son[maxe];

bool built[maxn];
int c[maxs][maxn];
int cnt,id[maxc];

int f[maxc][maxn][maxn]; // F[c][i][j]：颜色为 c 的联通块里，从第 i 点入、j 点出的方案数

inline void add(int x,int y){
	tot++;son[tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
}

inline void renumber(int x){ // 将颜色为 x 的点重新构图（编号），方便进行状压 DP
	memset_clear(id);
	cnt=0;
	for (int i=0;i<n;i++) if (color[i]==x) id[cnt++]=i;
}

inline void build_color(int x){ // 构造 x 颜色的 f 数组
	memset_clear(c);
	renumber(x);
	int s=1<<cnt;
	for (int i=0;i<cnt;i++) c[1<<i][i]=1;
	for (int i=0;i<s;i++)
	for (int j=0;j<cnt;j++) if (i&(1<<j)){
		for (int k=lnk[id[j]];k;k=nxt[k]) if ((color[son[k]]==x)&&())
	}
}

signed main(){
	n=read();m=read();
	for (int i=0;i<n;i++) color[i]=read();
	for (int i=0;i<m;i++) x[i]=read();
	for (int i=0;i<m;i++) y[i]=read(),add(x[i],y[i]),add(y[i],x[i]);
	for (int i=0;i<n;i++) if (!built[color[i]]) build_color(i);
	
}