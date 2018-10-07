/*
 * XJOI CONTEST1005 T1 白井黑子 (Kuroko)
 * 180925 By SkyWT
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

const int maxn=100005;
int n,k,ans=0;
int x[maxn],f[maxn];
struct num{
	int a,b;
};

inline int get_number(int x){
	int ret=1;
	while (x) ret=ret*(x%10),x/=10;
	return ret;
}

inline int qsm(int a,int b){
	int ret=1,w=a;
	while (b){
		if (b&1) ret=ret*w;
		w=w*w;b>>=1;
	}
	return ret;
}

signed main(){
	n=read();k=read();
	for (int i=1;i<=n;i++) x[i]=read();
	sort(x+1,x+1+n);
	for (int i=1;i<=n;i++) f[i]=get_number(x[i]);
	if (k==0){
		int cnt=0;
		for (int i=1;i<=n;i++) cnt+=(f[i]==1)||(f[i]==0);
		printf("%lld\n",n*n/2-cnt*cnt/2);
		return 0;
	}
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++) if (i!=j){
		int now=f[i]*f[j];
		if (now==0&&k==0) ans++;
		if (now==0) continue;
		double nowd=(double)log(now)/log(k);
		if (qsm(nowd,k)!=now) ans++;
	}
	printf("%lld\n",ans/2);
	return 0;
}