/*
 * XJOI CONTEST 1009 2018提高组模拟赛5
 * T1 落英
 * 180929 By SkyWT
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

const int maxn=105;
const int tt=998244353;
int case_number,t,n,k,a[maxn],va[maxn];

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

struct matrix{
	int a[3][3];
	void init(int number){
		if (number==-1){
			memset(a,0,sizeof(a));
			a[0][0]=a[1][1]=1;
		} else {
			memset(a,0,sizeof(a));
			a[0][0]=a[0][1]=number;
			a[1][0]=0;a[1][1]=1;
		}
	}
	void clear(){
		memset(a,0,sizeof(a));
	}
	matrix operator *(matrix b){
		matrix c; c.clear();
		for (int i=0;i<2;i++)
		for (int j=0;j<2;j++)
		for (int k=0;k<2;k++)
			c.a[i][j]=(c.a[i][j]+a[i][k]*b.a[k][j]%tt)%tt;
		return c;
	}
	matrix operator ^(int b){
		matrix ret; ret.init(-1);
		matrix w;   w.clear();
		for (int i=0;i<2;i++)
		for (int j=0;j<2;j++) w.a[i][j]=a[i][j];
		while (b){
			if (b%2) ret=ret*w;
			w=w*w;b>>=1;
		}
		return ret;
	}
};

inline int qsm(int a,int b){
	int ret=1,w=a;
	while (b){
		if (b&1) ret=ret*w%tt;
		w=w*w%tt;b>>=1;
	}
	return ret;
}

inline int calculate(int dnum,int znum){
	matrix now;
	now.init(dnum);
	now=now^znum;
	return now.a[0][1]%tt;
}

signed main(){
	case_number=read();
	t=read();n=read();k=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) va[i]=read();
	int ans;
	ans+=(calculate(t+va[1],k)-calculate(va[1],k)+tt)%tt;
	ans+=(calculate(t+va[2],k)-calculate(va[2],k)+tt)%tt;
	cout<<ans*qsm(t+1,tt-2)%tt<<endl;
	printf("%.4f\n",(double)ans/(t+1));
	return 0;
}