#include<bits/stdc++.h>

#define int long long
#define sqr(_) ((_)*(_))

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1e6+5;

int n,d;
int s[maxn],sum1[maxn],sum2[maxn],sum3[maxn];

int ans[maxn];

int get_sum1(int now,int x,int y){
	x=max(x,1ll); y=min(y,n);
	return (sum1[y]-sum1[x-1])*sqr(now) + (sum2[y]-sum2[x-1])*now + sum3[y]-sum3[x-1];
}

int get_sum2(int now,int x,int y){
	x=max(x,1ll); y=min(y,n);
	return (sum1[x]-sum1[y+1])*sqr(now) - (sum2[x]-sum2[y+1])*now + sum3[x]-sum3[y+1];
}

signed main(){
	#ifdef DEBUG
		freopen("data.in","r",stdin);
	#endif

	n=read(); d=read();
	for (int i=1;i<=n;i++)
		s[i]=read(),
		sum1[i]=sum1[i-1]+s[i],
		sum2[i]=sum2[i-1]+2*i*s[i],
		sum3[i]=sum3[i-1]+i*i*s[i];
	for (int i=1;i<=n;i++) ans[i]=get_sum1((d-i+1),i-d,i-1);

	for (int i=n;i>=1;i--)
		sum1[i]=sum1[i+1]+s[i],
		sum2[i]=sum2[i+1]+2*i*s[i],
		sum3[i]=sum3[i+1]+i*i*s[i];
	for (int i=1;i<=n;i++) ans[i]+=get_sum2((d+i),i,i+d-1);

	int prt=0;
	for (int i=1;i<=n;i++) prt=max(prt,ans[i]);
	printf("%lld\n",prt);
	return 0;
}