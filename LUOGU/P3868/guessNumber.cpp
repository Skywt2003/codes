#include<bits/stdc++.h>

#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=15;

int k,a[maxn],b[maxn],c[maxn];

int n=1;

int exgcd(int a,int b,int &x,int &y){
	if (b==0){x=1,y=0;return a;}
	int ret=exgcd(b,a%b,x,y);
	int tmp=x; x=y; y=tmp-a/b*y;
	return ret;
}

int inv(int a,int b){ //ax===1 (mod b)  <=>  ax+by===1
	int x,y;
	exgcd(a,b,x,y);
	return x;
}

int mul(int a,int b,int tt){
	int ret=0,w=a%tt;
	while (b){
		if (b&1) ret=(ret+w)%tt;
		w=(w+w)%tt; b>>=1;
	}
	return ret;
}

signed main(){
	k=read();
	for (int i=1;i<=k;i++) a[i]=read();
	for (int i=1;i<=k;i++) b[i]=read(),n*=b[i],a[i]=(a[i]%b[i]+b[i])%b[i];

	int ans=0;
	for (int i=1;i<=k;i++)
		c[i]=mul(n/b[i], (inv(n/b[i],b[i])+b[i])%b[i], n),
		ans=(ans+mul(a[i],c[i],n))%n;

	printf("%lld\n",(ans+n)%n);
	return 0;
}