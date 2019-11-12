#include<bits/stdc++.h>

#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1e5+5;
const int tt=1e9+7;

int typ,n,x,y;

int f[maxn];

int qsm(int a,int b){
	int ret=1,w=a%tt;
	while (b){
		if (b&1) ret=ret*w%tt;
		w=w*w%tt; b>>=1;
	}
	return ret;
}

int fac[maxn],inv[maxn];

void prebuild(){
	const int N=1e5;
	fac[0]=1;
	for (int i=1;i<=N;i++) fac[i]=fac[i-1]*i%tt;
	for (int i=0;i<=N;i++) inv[i]=qsm(fac[i],tt-2);
}

int C(int n,int m){
	if (n<m) return 0;
	return fac[n]*inv[m]%tt*inv[n-m]%tt;
}

signed main(){
	freopen("freshmen.in","r",stdin);
	freopen("freshmen.out","w",stdout);

	prebuild();

	typ=read();
	n=read(),x=read(),y=read();
	
	int ans1=0,ans2=0;
	for (int i=x;i<=y;i++){
		int now=0;
		for (int j=1;j<=n;j++){
			f[j]=(qsm(i-x+1,n-j) * C(n,j)%tt * ((j&1)?1:-1) +tt)%tt;
			now=(now+f[j])%tt;
		}
		ans1=(ans1+i)%tt;
		ans2=(ans2+now)%tt;
//		printf("i=%lld now=%lld\n",i,now);
	}
	printf("%lld\n",ans1*qsm(ans2,tt-2)%tt);
	return 0;
}
