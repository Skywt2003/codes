#include<cstdio>
#include<cstring>
#include<iostream>

#define int long long
using namespace std;

#define sqr(_) ((_)*(_))

const int maxn=1e5+5,tt=998244353;

int n,q,a[maxn];

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

signed main(){
	freopen("seg.in","r",stdin);
	freopen("seg.out","w",stdout);
	n=read();for (int i=1;i<=n;i++) a[i]=read();
	q=read();
	for (int i=1;i<=q;i++){
		int opt=read();
		if (opt==1){
			int l=read(),r=read(),k=read();
			for (int j=l;j<=r;j++) a[j]&=k;
		} else if (opt==2){
			int l=read(),r=read();
			int sum=0;
			for (int j=l;j<=r;j++) sum+=a[j];
			printf("%lld\n",sum);
		} else if (opt==3){
			int l=read(),r=read();
			int ans=0;
			for (int j=l;j<=r;j++){
				for (int k=l;k<=r;k++){
					ans=(ans+sqr(a[j]+a[k])%tt)%tt;
				}
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}