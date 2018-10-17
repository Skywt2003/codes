/*
 * XJOI CONTEST 1015
 * T1 - 买球
 * 181008 By SkyWT
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

#define write(_) cout<<#_<<" = "<<_<<endl;

#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxv=2000005,maxn=55;
int n,m,a[maxn],b[maxn],c[maxn],allv_a=0,allv_b=0;
int f[maxv],INF,ans;

signed main(){
	n=read();m=read();
	for (int i=1;i<=n;i++) a[i]=read(),allv_a+=a[i];
	for (int i=1;i<=n;i++) b[i]=read(),allv_b+=b[i];
	for (int i=1;i<=n;i++) c[i]=read();

	memset_clear_max(f);INF=ans=f[0];
	f[0]=0;
	for (int i=1;i<=n;i++)
		for (int j=allv_a;j>=a[i]-1;j--)
			if (f[j-(a[i]-1)]+c[i]<f[j]) f[j]=f[j-(a[i]-1)]+c[i];
	for (int i=m;i<=allv_a;i++) if (f[i]<ans) ans=f[i];

	memset_clear_max(f);
	f[0]=0;
	for (int i=1;i<=n;i++)
		for (int j=allv_b;j>=b[i]-1;j--)
			if (f[j-(b[i]-1)]+c[i]<f[j]) f[j]=f[j-(b[i]-1)]+c[i];
	for (int i=m;i<=allv_b;i++) if (f[i]<ans) ans=f[i];
	memset_clear_max(f);

	f[0]=0;
	for (int i=1;i<=n;i++)
		for (int j=allv_a+allv_b;j>=a[i]+b[i];j--)
			if (f[j-(a[i]+b[i])]+c[i]<f[j]) f[j]=f[j-(a[i]+b[i])]+c[i];
	for (int i=2*m-1;i<=allv_a+allv_b;i++) if (f[i]<ans) ans=f[i];
	
	printf("%lld\n",(ans==INF)?(-1):(ans));
	return 0;
}