/*
 * XJOI CONTEST1002 T6 wzz 与 zzy
 * 180921 By SkyWT
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

const int maxn=105;
int n,m,all_number=0;
int f[maxn][maxn][maxn];
int ans=0;

inline int plus_mod(int &x,int y){
	x=(x+y)%tt;
}

signed main(){
	n=read();m=read();all_number=max(n,m);
	memset_clear(f);
	f[0][0][0]=1;
	for (int i=0;i<=all_number;i++)
	for (int x=0;x<=n*2;x++)
	for (int y=0;y<=m*2;y++){
		plus_mod(f[i+1][x][y],f[i][x][y]);
		if (i+1<=n) plus_mod(f[i+1][x^(i+1)][y],f[i][x][y]);
		if (i+1<=m) plus_mod(f[i+1][x][y^(i+1)],f[i][x][y]);
		// if (f[i][x][y]>0) write_3(i,x,y);
		// if ((i==all_number)&&(x<y)&&(f[i][x][y])) printf("Added: %lld\n",f[i][x][y]);
		if ((i==all_number)&&(x<y)) plus_mod(ans,f[i][x][y]);
	}
	printf("%lld\n",ans);
	return 0;
}