/*
 * Vjudge CONTEST257241 高斯消元
 * A - 开关问题
 * 180928 By SkyWT
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

#define write(_) cout<<#_<<" = "<<_<<endl
#define write_2(_,__) cout<<#_<<" = "<<_<<" , "<<#__<<" = "<<__<<endl
#define write_3(_,__,___) cout<<#_<<" = "<<_<<" , "<<#__<<" = "<<__<<" , "<<#___<<" = "<<___<<endl

#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=35;
int T,n;
int ans=0;
bool a[maxn][maxn],s[maxn],t[maxn];

inline void init(){
	memset_clear(a);
	ans=0;
}

inline void swap_line(int i,int j){
	if (i==j) return;
	for (int k=1;k<=n+1;k++) swap(a[i][k],a[j][k]);
}

inline void subtract_line(int i,int j){
	for (int k=1;k<=n+1;k++) a[i][k]^=a[j][k];
}

inline void Gaussian_Elimination(){
	for (int i=1;i<=n;i++){
		if (!a[i][i]){
			int k=-1;
			for (int j=i+1;j<=n;j++) if (a[j][i]) {k=j;break;}
			if (k==-1) continue;
			swap_line(i,k);
		}
		for (int j=1;j<=n;j++) if ((j!=i)&&(a[j][i])) subtract_line(j,i);
	}
}

inline void print_matrix(){
	printf("MATRIX: ================\n");
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n+1;j++) printf("%d ",a[i][j]);
		printf("\n");
	}
	printf("========================\n");
}

signed main(){
	T=read();
	while (T--){
		init();
		n=read();
		for (int i=1;i<=n;i++) s[i]=read();
		for (int i=1;i<=n;i++) t[i]=read(),t[i]=t[i]^s[i];
		for (int i=1;i<=n;i++) a[i][n+1]=t[i];
		int x=read(),y=read();
		while (x||y){
			a[y][x]=1;
			x=read(),y=read();
		}
		for (int i=1;i<=n;i++) a[i][i]=true;

		// print_matrix();
		Gaussian_Elimination();
		// print_matrix();

		bool prt=false;
		for (int i=1;i<=n;i++){
			bool flag=true;
			for (int j=1;j<=n;j++) if (a[i][j]) flag=false;
			if (flag&&a[i][n+1]) {printf("Oh,it's impossible~!!\n");prt=true;break;};
			ans+=flag;
		}
		if (!prt) printf("%lld\n",(int)1<<ans);
	}
	return 0;
}