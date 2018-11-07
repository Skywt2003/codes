#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#define int long long

using namespace std;
const int maxn=20,maxs=(1<<17)+10;
const int tt=998244353;

int n,m,s;
int p[maxn][maxn];
int bet[maxs],inv[maxs];
int f[maxs];
int ans=0;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

namespace math{
	inline int qsm(int a,int b){
		int ret=1,w=a%tt;
		while (b){
			if (b&1) ret=ret*w%tt;
			w=w*w%tt;b>>=1;
		}
		return ret;
	}

	inline int get_inverse(int x){
		return qsm(x,tt-2);
	}

	inline int lowbit(int x){
		return x&(-x);
	}
}

inline void add_mod(int &x,int y){
	x=(x+y)%tt;
}

inline void sub_mod(int &x,int y){
	x=(x-y+tt)%tt;
}

inline void mul_mod(int &x,int y){
	x=(x*y)%tt;
}

inline void build_bet(){
	for (int k=0;k<s;k++){
		bet[k]=1;
		for (int i=0;i<n;i++) if (k&(1<<i)){
			for (int j=i+1;j<n;j++) if (k&(1<<j)){
				mul_mod(bet[k],p[i][j]);
			}
		}
		inv[k]=math::get_inverse(bet[k]);
	}
}

signed main(){
	n=read();m=read();s=1<<n;

	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++) p[i][j]=1;
	}

	for (int i=0;i<m;i++){
		int x=read()-1,y=read()-1;
		p[x][y]=p[y][x]=read();
	}

	build_bet();

	f[0]=inv[0]=1;
	for (int k=1;k<s;k++){
		int tmp=1;

		int w=k^math::lowbit(k);
		for(int ss=(w-1)&w;~ss;ss=(ss-1)&w){
			int t=ss|math::lowbit(k);
			sub_mod(tmp,f[t]*bet[k]%tt*inv[t]%tt*inv[k-t]%tt);
			if (!ss) break;
		}
		f[k]=tmp;

		for (int i=0;i<n;i++) if (k&(1<<i)){
			for (int j=0;j<n;j++) if (!(k&(1<<j))){
				mul_mod(tmp,p[i][j]);
			}
		}
		add_mod(ans,tmp);
	}

	cout<<ans<<endl;

	return 0;
}