#include<bits/stdc++.h>

#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=2e5+5,maxx=1e6+5;
const int N=1e6;

const int tt=1e9+7;

int n,a[maxx];
int f[maxx],cnt[maxx];
int pow2[maxn];
int ans=0;

signed main(){
	n=read();
	for (int i=1;i<=n;i++) a[read()]++;

	for (int i=1;i<=N;i++)
		for (int j=i;j<=N;j+=i)
			cnt[i]+=a[j];
	pow2[0]=1;
	for (int i=1;i<=n;i++) pow2[i]=pow2[i-1]*2%tt;

	for (int i=N;i>1;i--){
		f[i]=cnt[i]*pow2[cnt[i]-1]%tt;
		for (int j=i+i;j<=N;j+=i) f[i]=(f[i]-f[j]+tt)%tt;
		ans=(ans+i*f[i]%tt)%tt;
	}
	
	printf("%lld\n",ans);
	return 0;
}